
/******************************************************************************
*
*   FILE
*   ----
*   xdrManagerCom.c
*
*   History
*   -------
*   2013-02-07   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_ksxdr
#define OV_COMPILE_LIBRARY_ksxdr
#endif


#include "ksxdr.h"
#include "libov/ov_macros.h"
#include "libov/ov_vendortree.h"
#include "libov/ov_result.h"
#include "ks_logfile.h"
#include "ksxdr_config.h"
#include "ksbase_helper.h"
#include "KSDATAPACKET_xdrhandling.h"
#include "ksxdr_services.h"

void ksxdr_xdrManagercom_Callback(OV_INSTPTR_ov_domain instanceCalled, OV_INSTPTR_ov_domain instanceCalling);


OV_DLLFNCEXPORT void ksxdr_xdrManagerCom_startup(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_ksxdr_xdrManagerCom pinst = Ov_StaticPtrCast(ksxdr_xdrManagerCom, pobj);

    /* do what the base class does first */
    ov_object_startup(pobj);

    /* do what */
    pinst->v_cycInterval = 5000; /*	cycle every 5 seconds at first	*/
    pinst->v_actimode = 1;
    pinst->v_Tries = 0;

    return;
}

OV_DLLFNCEXPORT void ksxdr_xdrManagerCom_shutdown(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
	OV_INSTPTR_ksxdr_xdrManagerCom	thisMngCom = Ov_StaticPtrCast(ksxdr_xdrManagerCom, pobj);
	OV_INSTPTR_ksbase_Manager		pManager = NULL;
	OV_INSTPTR_ksxdr_xdrClient		xdrClient = NULL;
	OV_ANY							servername;

	if(thisMngCom->v_UseShortCut == TRUE)
	{

		KS_logfile_debug(("%s: unregister: using shortCut", thisMngCom->v_identifier));
		pManager = Ov_StaticPtrCast(ksbase_Manager, Ov_GetFirstChild(ov_instantiation, pclass_ksbase_Manager));
		if(!pManager)
		{
			KS_logfile_error(("%s: shutdown: no Manager here. Cannot unregister", thisMngCom->v_identifier));
			return;
		}

		KS_logfile_debug(("%s: unregistering MANAGER ksxdr protocol", thisMngCom->v_identifier));
		if(Ov_Fail(ksbase_Manager_unregister("MANAGER", 2, KSXDR_IDENTIFIER)))
		{
			thisMngCom->v_RegisterState = 128;	/*	set register error	*/
			thisMngCom->v_cycInterval = 5000;	/*	5 seconds cyctime for next start up	*/
			thisMngCom->v_Tries = 0;		/*	for next start up reset counter	*/
			return;
		}
		else
		{
			thisMngCom->v_RegisterState = 0;	/*	set state to unregistered	*/
			thisMngCom->v_cycInterval = 5000;	/*	5 seconds cyctime for next start up	*/
			thisMngCom->v_Tries = 0;
			return;
		}
	}
	else
	{/*	find the first xdrClient in containment to request unregister	*/
		xdrClient = Ov_StaticPtrCast(ksxdr_xdrClient, Ov_GetFirstChild(ov_containment, thisMngCom));
		if(xdrClient)
		{
			while(xdrClient && (Ov_GetParent(ov_instantiation, xdrClient) != pclass_ksxdr_xdrClient))
				xdrClient = Ov_StaticPtrCast(ksxdr_xdrClient, Ov_GetNextChild(ov_containment, xdrClient));
		}

		servername.value.vartype = OV_VT_VOID;
		servername.value.valueunion.val_string = NULL;
		ov_vendortree_getservername(&servername, NULL);

		if(xdrClient)
			ksxdr_xdrClient_requestUnRegister(Ov_StaticPtrCast(ksbase_ClientBase, xdrClient), NULL, servername.value.valueunion.val_string, 2, NULL, NULL);

	}
	thisMngCom->v_RegisterState = 0;	/*	set state to unregistered	*/
	thisMngCom->v_cycInterval = 5000;	/*	5 seconds cyctime for next start up	*/
	thisMngCom->v_Tries = 0;


    /* set the object's state to "shut down" */
    ov_object_shutdown(pobj);

    return;
}



OV_DLLFNCEXPORT void ksxdr_xdrManagerCom_typemethod (
	OV_INSTPTR_ksbase_ComTask	this
) {
    /*
    *   local variables
    */
	OV_INSTPTR_ksxdr_xdrManagerCom	thisMngCom = Ov_StaticPtrCast(ksxdr_xdrManagerCom, this);
	OV_INSTPTR_ksbase_Manager 		pManager = NULL;
	OV_INSTPTR_ksbase_ComTask		pListener = NULL;
	OV_INSTPTR_ov_class				pClListener = NULL;
	OV_INT							port = -1;
	OV_STRING						OptValTemp = NULL;
	OV_ELEMENT						elemPort;
	OV_ELEMENT						ListenerElement;
	OV_ANY							servername;
	OV_INSTPTR_ksxdr_xdrClient		xdrClient = NULL;
	OV_RESULT						result;

	switch(thisMngCom->v_RegisterState)
	{

	case 0:	/*	if not registered or registered successfully (in latter case typemethod is slowed down to TTL * 0.9) or error (in this case typemethod is slowed down for retries)	*/
	case 2:
	case 128:
		if(thisMngCom->v_Tries < 3)
		{
			/*	if the OwnPort is not set check commandline options and if they are not set check for a TCPListener (default binding)	*/
			if(!thisMngCom->v_OwnPort || !(*thisMngCom->v_OwnPort) || ov_string_compare(thisMngCom->v_OwnPort, "-1") == OV_STRCMP_EQUAL)
			{
				/*
				 * Determine port
				 */
				ov_memstack_lock();
				port = ov_vendortree_getport();
				if(port < 0 )// PORT not set
				{
					//check environment Variable OWNPORT (for compatibility reasons)
					if (getenv("OWNPORT")) //OWNPORT set
					{
						OptValTemp = getenv("OWNPORT");
						ov_string_setvalue(&thisMngCom->v_OwnPort, OptValTemp);
					}
					else
					{	//check option KS_PORT
						OptValTemp = ov_vendortree_getcmdlineoption_value("KS_PORT");
						if(OptValTemp && *OptValTemp)
						{
							ov_string_setvalue(&thisMngCom->v_OwnPort, OptValTemp);
						}
						else	/*	check the TCPListener (default binding) WITHOUT creating a dependency on TCPBind	*/
						{	/*	get TCPlistener class	*/
							/*	ov_searchchild does not work here, as ov_instanciation lacks the property OV_AP_LOCAL	*/
							pClListener = Ov_GetFirstChild(ov_inheritance, pclass_ksbase_ComTask);
							while(pClListener)
							{
								if(ov_string_compare(pClListener->v_identifier, "TCPListener") == OV_STRCMP_EQUAL)
									break;
								pClListener = Ov_GetNextChild(ov_inheritance, pClListener);
							}
							if(!pClListener)
							{
								KS_logfile_error(("%s: typemethod: OwnPort not set and class TCPListener (default binding) not found. retry in 2 minutes.", this->v_identifier));
								this->v_cycInterval = 120000;	/*	retry in 2 minutes	*/
								ov_memstack_unlock();
								return;
							}
							/*	get TCPListener instance	*/
							pListener = Ov_StaticPtrCast(ksbase_ComTask, Ov_GetFirstChild(ov_instantiation, pClListener));
							if(!pListener)
							{
								KS_logfile_error(("%s: typemethod: OwnPort not set and TCPListner instance (default binding) not found. retry in 2 minutes.", this->v_identifier));
								this->v_cycInterval = 120000;	/*	retry in 2 minutes	*/
								ov_memstack_unlock();
								return;
							}

							/*	read out port variable	*/
							ListenerElement.elemtype = OV_ET_OBJECT;
							ListenerElement.pobj = Ov_StaticPtrCast(ov_object, pListener);

							if(Ov_Fail(ov_element_searchpart(&ListenerElement, &elemPort, OV_ET_VARIABLE, "port")))
							{
								KS_logfile_error(("%s: typemethod: element port not found. deactivating registration.", this->v_identifier));
								ov_memstack_unlock();
								this->v_actimode = 0;
								return;
							}
							if(elemPort.elemtype == OV_ET_VARIABLE)
							{
								if(elemPort.pvalue)
								{
									port = *((OV_INT*) elemPort.pvalue);
								}
								else
									KS_logfile_error(("element value* is NULL"));
								OptValTemp = ov_memstack_alloc(12);	/*	this way prevent us from NULL-pointer exceptions in ov_string_print	*/
								if(OptValTemp)
								{
									sprintf(OptValTemp, "%ld", port);
									ov_string_setvalue(&thisMngCom->v_OwnPort, OptValTemp);
								}
								else
								{
									KS_logfile_error(("%s typemethod: could not set port: HEAPOUTOFMEMORY", thisMngCom->v_identifier));
								}
							}
							else
							{
								KS_logfile_error(("%s: typemethod: could not obtain port from TCPListener. deactivating registration.", this->v_identifier));
								ov_memstack_unlock();
								this->v_actimode = 0;
								return;
							}
						}
					}
				}
				else
				{
					OptValTemp = ov_memstack_alloc(12);
					sprintf(OptValTemp, "%ld", port);
					ov_string_setvalue(&thisMngCom->v_OwnPort, OptValTemp);
				}
				ov_memstack_unlock();
			}
			/*************************************************************************************************************************************************************
			 * here we definitely know the port
			 ************************************************************************************************************************************************************/

			if(thisMngCom->v_UseShortCut == TRUE)
			{
				KS_logfile_debug(("%s: typemethod: using shortCut", this->v_identifier));
				pManager = Ov_StaticPtrCast(ksbase_Manager, Ov_GetFirstChild(ov_instantiation, pclass_ksbase_Manager));
				if(!pManager)
				{
					KS_logfile_error(("%s: typemethod: no Manager here. Cannot register", this->v_identifier));
					return;
				}

				KS_logfile_debug(("%s: registering MANAGER ksxdr protocol on port %s", thisMngCom->v_identifier, thisMngCom->v_OwnPort));
				if(Ov_Fail(ksbase_Manager_register("MANAGER", 2, KSXDR_IDENTIFIER, thisMngCom->v_OwnPort, 30)))
				{
					thisMngCom->v_RegisterState = 128;	/*	set register error	*/
					thisMngCom->v_Tries++;
					return;
				}
				else
				{
					thisMngCom->v_RegisterState = 2;	/*	set state to registered and slow down typemethod	*/
					thisMngCom->v_cycInterval = 30000;	/*	re-register every 30 seconds (assuming rootcomtask runs at 1 msec)	*/
					thisMngCom->v_Tries = 0;
					return;
				}
			}
			else
			{
				servername.value.vartype = OV_VT_VOID;
				servername.value.valueunion.val_string = NULL;
				ov_vendortree_getservername(&servername, NULL);

				/*	find the first xdrClient in containment to request register	*/
				xdrClient = Ov_StaticPtrCast(ksxdr_xdrClient, Ov_GetFirstChild(ov_containment, this));
				if(xdrClient)
				{
					while(xdrClient && (Ov_GetParent(ov_instantiation, xdrClient) != pclass_ksxdr_xdrClient))
						xdrClient = Ov_StaticPtrCast(ksxdr_xdrClient, Ov_GetNextChild(ov_containment, xdrClient));
				}

				if(!xdrClient)
				{/*	no xdrClient in containment --> create one	*/
					result = Ov_CreateObject(ksxdr_xdrClient, xdrClient, this, "xdrClient");
					if(Ov_Fail(result))
					{
						ov_memstack_lock();
						KS_logfile_error(("%s: typemethod: could not create xdrClient. reason: %s", this->v_identifier, ov_result_getresulttext(result)));
						ov_memstack_unlock();
						this->v_actimode = 0;
						thisMngCom->v_RegisterState = 128;
						return;
					}
					xdrClient->v_holdConnection = TRUE;
				}
				ksxdr_xdrClient_requestRegister(Ov_StaticPtrCast(ksbase_ClientBase, xdrClient), NULL, servername.value.valueunion.val_string, 2, strtol(thisMngCom->v_OwnPort, NULL, 10), 30, Ov_StaticPtrCast(ov_domain, this), &ksxdr_xdrManagercom_Callback);
				thisMngCom->v_RegisterState = 1;	/*	set state to waiting for answer	*/
				thisMngCom->v_cycInterval = 5000;	/*	used as a timeout: 5 seconds should be enough for a local connection (assuming rootcomtask runs at 1 msec)	*/
				thisMngCom->v_Tries++;
				return;
			}

		}
		else
		{
			KS_logfile_error(("%s: registering at Manager failed 3 times. retry in 2 minutes.", thisMngCom->v_identifier));
			this->v_cycInterval = 120000;	/*	retry in 2 minutes	*/
			thisMngCom->v_Tries = 0;
			/*	reset client	*/
			/*	find the first xdrClient in containment to issue reset	*/
			xdrClient = Ov_StaticPtrCast(ksxdr_xdrClient, Ov_GetFirstChild(ov_containment, this));
			if(xdrClient)
			{
				while(xdrClient && (Ov_GetParent(ov_instantiation, xdrClient) != pclass_ksxdr_xdrClient))
					xdrClient = Ov_StaticPtrCast(ksxdr_xdrClient, Ov_GetNextChild(ov_containment, xdrClient));
			}
			ksxdr_xdrClient_reset(Ov_StaticPtrCast(ksbase_ClientBase, xdrClient));
			return;
		}
		break;

	case 1: 	/*	waiting for answer	*/
		/*	the callbackfunction sets state to registered or to error. if typemethod is run in this state a timeout occurred	*/
		/*	increment Tries, reset Client, set state to error and be called again in 5 seconds	*/
		thisMngCom->v_Tries++;

		xdrClient = Ov_StaticPtrCast(ksxdr_xdrClient, Ov_GetFirstChild(ov_containment, this));
		if(xdrClient)
		{
			while(xdrClient && (Ov_GetParent(ov_instantiation, xdrClient) != pclass_ksxdr_xdrClient))
				xdrClient = Ov_StaticPtrCast(ksxdr_xdrClient, Ov_GetNextChild(ov_containment, xdrClient));
		}
		ksxdr_xdrClient_reset(Ov_StaticPtrCast(ksbase_ClientBase, xdrClient));

		thisMngCom->v_RegisterState = 128;
		thisMngCom->v_cycInterval = 5000;
	break;

	}
	return;
}

void ksxdr_xdrManagercom_Callback(OV_INSTPTR_ov_domain instanceCalled, OV_INSTPTR_ov_domain instanceCalling)
{
	OV_INSTPTR_ksbase_ClientBase	xdrClient = Ov_StaticPtrCast(ksbase_ClientBase, instanceCalling);
	OV_INSTPTR_ksxdr_xdrManagerCom	this = Ov_StaticPtrCast(ksxdr_xdrManagerCom, instanceCalled);
	OV_RESULT						ksResult;
	OV_RESULT						result;

	result = ksxdr_xdrClient_processRegister(xdrClient, NULL, &ksResult);
	if(Ov_Fail(result))
	{	ov_memstack_lock();
		KS_logfile_error(("%s: callback: error processing answer: %s", this->v_identifier, ov_result_getresulttext(result)));
		ov_memstack_unlock();
		this->v_RegisterState = 128;	/*	error	*/
		return;
	}

	ksbase_free_KSDATAPACKET(&(Ov_StaticPtrCast(ksxdr_xdrClient, xdrClient)->v_dataReceived));
	KS_logfile_debug(("%s: callback: register processed: result: %lu", this->v_identifier, result));
	if(ksResult == KS_ERR_OK)
	{
		this->v_RegisterState = 2;	/*	registered	*/
		this->v_Tries = 0;
		this->v_cycInterval = 30000;	/*	reregister in 30 seconds	*/
		this->v_NextExecTime.secs += 30;
		return;
	}
	else
	{
		this->v_RegisterState = 128;	/*	error	*/
		this->v_ErrCode = ksResult;
		return;
	}

	return;
}
