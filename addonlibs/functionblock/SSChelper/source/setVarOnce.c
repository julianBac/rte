
/******************************************************************************
*
*   FILE
*   ----
*   setVarOnce.c
*
*   History
*   -------
*   2017-09-24   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_SSChelper
#define OV_COMPILE_LIBRARY_SSChelper
#endif


#include "SSChelper.h"
#include "libov/ov_macros.h"

#include "utilities.h"


OV_DLLFNCEXPORT void SSChelper_setVarOnce_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_SSChelper_setVarOnce pinst = Ov_StaticPtrCast(SSChelper_setVarOnce, pfb);
    OV_INSTPTR_ov_object target=NULL;
    OV_INSTPTR_ov_object trigger=NULL;
    OV_RESULT result = OV_ERR_OK;
    OV_ANY triggerValue;
    OV_BOOL extTrigger = FALSE;

    // reset trigger out signal and wait one cycle
    if(pinst->v_trigOut){
    	pinst->v_trigOut = FALSE;
    	return;
    }

    // handle trigger input with priority
    if(pinst->v_trig){
    	result |= SSChelper_getObjectAndVarnameFromSetVariable(Ov_PtrUpCast(ov_object,pinst),pinst->v_path,&target,&pinst->v_port);
    	result |= SSChelper_setNamedVariable(target,pinst->v_port,&pinst->v_var);
    	pinst->v_error = Ov_Fail(result);
    	Ov_SetAnyValue(&pinst->v_varOut, &pinst->v_var);
    	pinst->v_trigOut = TRUE;
    }
    // handle external trigger
    else if(pinst->v_pathTrig != NULL && pinst->v_portTrig != NULL){
    	// get trigger value
    	result |= SSChelper_getObjectAndVarnameFromSetVariable(Ov_PtrUpCast(ov_object,pinst),pinst->v_pathTrig,&trigger,&pinst->v_portTrig);
    	if(Ov_OK(result)){
    	    SSChelper_getNamedVariable(trigger,pinst->v_portTrig,&triggerValue);
    	    //Check trigger datatype and evaluate trigger
    	    if(triggerValue.value.vartype == OV_VT_VOID){
    	    	extTrigger = FALSE;
    	    }else if(triggerValue.value.vartype == OV_VT_STRING){
    	    	extTrigger = triggerValue.value.valueunion.val_string != NULL &&
    	    			ov_string_compare(triggerValue.value.valueunion.val_string, "") != OV_STRCMP_EQUAL &&
    	    			ov_string_compare(triggerValue.value.valueunion.val_string, " ")!= OV_STRCMP_EQUAL ;
    	    }else{
    	    	extTrigger = triggerValue.value.valueunion.val_bool;
    	    }
    	}

    	if(extTrigger){
    		//Write value
        	result |= SSChelper_getObjectAndVarnameFromSetVariable(Ov_PtrUpCast(ov_object,pinst),pinst->v_path,&target,&pinst->v_port);
    		result |= SSChelper_setNamedVariable(target,pinst->v_port,&pinst->v_var);

    		// Reset trigger
			OV_ANY anyNull;
			Ov_SetAnyValue(&anyNull, NULL);
			result |= SSChelper_setNamedVariable(trigger,pinst->v_portTrig, &anyNull);

			//Write results
        	pinst->v_error = Ov_Fail(result);
        	Ov_SetAnyValue(&pinst->v_varOut, &pinst->v_var);
        	pinst->v_trigOut = TRUE;
    	}
    }

    return;
}

