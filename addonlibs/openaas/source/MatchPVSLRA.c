
/******************************************************************************
*
*   FILE
*   ----
*   MatchPVSLRA.c
*
*   History
*   -------
*   2017-03-09   File created
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
#include "libov/ov_macros.h"


OV_DLLFNCEXPORT OV_UINT openaas_MatchPVSLRA_matchPVSLRA(OV_STRING requirementListPath, OV_STRING assuranceListPath, OV_BOOL *match, OV_STRING *matchText, OV_STRING *errorText) {

	OV_INSTPTR_ov_object requirementList = NULL;
	OV_INSTPTR_ov_object assuranceList = NULL;

	requirementList = ov_path_getobjectpointer(requirementListPath, 2);
	if (!requirementList){
		ov_string_setvalue(errorText, "requirementListPath is not valid");
		return 1;
	}
	if (!Ov_CanCastTo(openaas_PropertyValueStatementList, requirementList)){
		ov_string_setvalue(errorText, "requirementListPath is not a path to an PropertyValueStatement");
		return 1;
	}

	assuranceList = ov_path_getobjectpointer(assuranceListPath, 2);
	if (!assuranceList){
		ov_string_setvalue(errorText, "assuranceListPath is not valid");
		return 1;
	}
	if (!Ov_CanCastTo(openaas_PropertyValueStatementList, assuranceList)){
		ov_string_setvalue(errorText, "assuranceListPath is not a path to an PropertyValueStatement");
		return 1;
	}

	OV_INSTPTR_openaas_PropertyValueStatement requirement = NULL;
	OV_INSTPTR_openaas_PropertyValueStatement assurance = NULL;
	OV_UINT assuranceSize = 0;
	Ov_ForEachChildEx(ov_containment, Ov_DynamicPtrCast(ov_domain, assuranceList), assurance, openaas_PropertyValueStatement){
		if (assurance->v_ExpressionSemantic == ASSURANCE){
			assuranceSize++;
		}
	}

	OV_UINT assuranceCounter = 0;
	OV_BOOL tmpMatch = false;
	OV_STRING tmpErrorText = NULL;
	OV_STRING tmpMatchText = NULL;
	OV_STRING requirementPath = NULL;
	OV_STRING assurancePath = NULL;
	Ov_ForEachChildEx(ov_containment, Ov_DynamicPtrCast(ov_domain, requirementList), requirement, openaas_PropertyValueStatement){
		if (requirement->v_ExpressionSemantic == REQUIREMENT){
			if (assuranceSize == 0){
				ov_string_print(matchText, "requirement %s do not match with the assurances", requirement->v_identifier);
				*match = FALSE;
				ov_database_free(requirementPath);
				ov_database_free(assurancePath);
				ov_database_free(tmpErrorText);
				ov_database_free(tmpMatchText);
				return 0;
			}
			assuranceCounter = 0;
			Ov_ForEachChildEx(ov_containment, Ov_DynamicPtrCast(ov_domain, assuranceList), assurance, openaas_PropertyValueStatement){
				if (assurance->v_ExpressionSemantic == ASSURANCE){
					assuranceCounter++;
					ov_string_setvalue(&requirementPath, requirementListPath);
					ov_string_append(&requirementPath, "/");
					ov_string_append(&requirementPath, requirement->v_identifier);
					ov_string_setvalue(&assurancePath, assuranceListPath);
					ov_string_append(&assurancePath, "/");
					ov_string_append(&assurancePath, assurance->v_identifier);
					if (openaas_MatchPVSRA_matchPVSRA(requirementPath, assurancePath, &tmpMatch, &tmpMatchText, &tmpErrorText) != 0){
						ov_string_setvalue(errorText, tmpErrorText);
						ov_database_free(tmpMatchText);
						ov_database_free(tmpErrorText);
						ov_database_free(requirementPath);
						ov_database_free(assurancePath);
						return 1;
					}
					if (tmpMatch == true){
						ov_database_free(tmpMatchText);
						ov_database_free(tmpErrorText);
						ov_database_free(requirementPath);
						ov_database_free(assurancePath);
						break;
					}
					if (tmpMatch == false && assuranceCounter >= assuranceSize){
						*match = false;
						ov_string_print(matchText, "requirement %s do not match with the assurances, ", requirement->v_identifier);
						ov_string_append(matchText, tmpMatchText);
						ov_database_free(tmpMatchText);
						ov_database_free(tmpErrorText);
						ov_database_free(requirementPath);
						ov_database_free(assurancePath);
						return 0;
					}
				}
			}
		}
	}
	*match = true;
    return 0;
}

OV_DLLFNCEXPORT void openaas_MatchPVSLRA_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_openaas_MatchPVSLRA pinst = Ov_StaticPtrCast(openaas_MatchPVSLRA, pfb);
    pinst->v_error = 0;
	ov_string_setvalue(&pinst->v_errortext, "");
	ov_string_setvalue(&pinst->v_matchText, "");
	pinst->v_match = false;

    pinst->v_error = openaas_MatchPVSLRA_matchPVSLRA(pinst->v_List1Path, pinst->v_List2Path, &pinst->v_match, &pinst->v_matchText, &pinst->v_errortext);
    if (pinst->v_error != 0 || pinst->v_match == false)
    	return;
    pinst->v_error = openaas_MatchPVSLRA_matchPVSLRA(pinst->v_List2Path, pinst->v_List1Path, &pinst->v_match, &pinst->v_matchText, &pinst->v_errortext);
    return;
}

