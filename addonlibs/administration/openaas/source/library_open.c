
/******************************************************************************
*
*   FILE
*   ----
*   library_open.c
*
*   History
*   -------
*   2014-10-13   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/

#ifndef OV_COMPILE_LIBRARY_openaas
#define OV_COMPILE_LIBRARY_openaas
#endif
#include "openaas.h"
#ifdef ov_library_open_openaas
#undef ov_library_open_openaas
#endif

#include "libov/ov_macros.h"
#include "libov/ov_result.h"
#include "libov/ov_logfile.h"
#include "libov/ov_memstack.h"
#include "libov/ov_result.h"
#include "libov/ov_time.h"

 OV_RESULT ov_library_setglobalvars_openaas_new(void) {
	OV_RESULT result = OV_ERR_OK;
	/*
	 *    set the global variables of the original version
	 *    and if successful, load other libraries
	 *    and create some objects
	 */
	 result = ov_library_setglobalvars_openaas();
	 if (Ov_Fail(result)){
		 return result;
	 }
	/*
	 * Your code goes here.
	 */
	 OV_INSTPTR_ov_library pLibLIFECYCLEENTRY = NULL;
	 Ov_ForEachChildEx(ov_instantiation, pclass_ov_library, pLibLIFECYCLEENTRY, ov_library){
		if(ov_string_compare(pLibLIFECYCLEENTRY->v_identifier, "lifeCycleEntry") == OV_STRCMP_EQUAL){
			break;
		}
	 }
	 if(!pLibLIFECYCLEENTRY){
		result = Ov_CreateObject(ov_library, pLibLIFECYCLEENTRY, &(pdb->acplt), "lifeCycleEntry");
		if(Ov_Fail(result)){
			ov_logfile_error("openaas: Fatal: Couldn't load dependency Library lifeCycleEntry Reason: %s", ov_result_getresulttext(result));
			return result;
		}
	 }

	 OV_INSTPTR_ov_library pLibPROPERTYVALUESTATEMENT = NULL;
	 Ov_ForEachChildEx(ov_instantiation, pclass_ov_library, pLibPROPERTYVALUESTATEMENT, ov_library){
		if(ov_string_compare(pLibPROPERTYVALUESTATEMENT->v_identifier, "propertyValueStatement") == OV_STRCMP_EQUAL){
			break;
		}
	 }
	 if(!pLibPROPERTYVALUESTATEMENT){
		result = Ov_CreateObject(ov_library, pLibPROPERTYVALUESTATEMENT, &(pdb->acplt), "propertyValueStatement");
		if(Ov_Fail(result)){
			ov_logfile_error("openaas: Fatal: Couldn't load dependency Library propertyValueStatement Reason: %s", ov_result_getresulttext(result));
			return result;
		}
	 }


	 OV_INSTPTR_ov_library pLibMESSAGESYS = NULL;
	 Ov_ForEachChildEx(ov_instantiation, pclass_ov_library, pLibMESSAGESYS, ov_library){
		if(ov_string_compare(pLibMESSAGESYS->v_identifier, "MessageSys") == OV_STRCMP_EQUAL){
			break;
		}
	 }
	 if(!pLibMESSAGESYS){
		result = Ov_CreateObject(ov_library, pLibMESSAGESYS, &(pdb->acplt), "MessageSys");
		if(Ov_Fail(result)){
			ov_logfile_error("openaas: Fatal: Couldn't load dependency Library MessageSys Reason: %s", ov_result_getresulttext(result));
			return result;
		}
	 }

	return result;
	}

 OV_DLLFNCEXPORT OV_LIBRARY_DEF *ov_library_open_openaas(void) {
 	/* local variables */
 	static OV_LIBRARY_DEF *OV_LIBRARY_DEF_openaas_new;
 	/*
 	*       replace the 'setglobalvars' function created by the code generator
 	*       with a new one.
 	*/
 	OV_LIBRARY_DEF_openaas_new = ov_library_open_openaas_old();
 	OV_LIBRARY_DEF_openaas_new->setglobalvarsfnc = ov_library_setglobalvars_openaas_new;
 	return OV_LIBRARY_DEF_openaas_new;
  }


