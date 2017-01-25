/******************************************************************************
 *
 *   FILE
 *   ----
 *   nodeStoreFunctions.c
 *
 *   History
 *   -------
 *   2014-10-21   File created
 *
 *******************************************************************************
 *
 *   This file is generated by the 'acplt_builder' command
 *
 ******************************************************************************/

#ifndef OV_COMPILE_LIBRARY_opcua
#define OV_COMPILE_LIBRARY_opcua
#endif

#include "libov/ov_macros.h"
#include "ksbase.h"
#include "opcua.h"
#include "opcua_helpers.h"
#include "NoneTicketAuthenticator.h"
#include "libov/ov_path.h"
#include "libov/ov_memstack.h"
#include "ks_logfile.h"

extern OV_INSTPTR_opcua_uaServer opcua_pUaServer;


OV_DLLFNCEXPORT UA_StatusCode opcua_nodeStoreFunctions_opcuaVariableNodeToOv(
		void *handle, UA_VariableNode* opcuaNode, OV_INSTPTR_opcua_variableNode* ovNode, UA_NodeId *parrentNode) {

	OV_RESULT result = 0;
	OV_INSTPTR_ov_domain ptr = NULL;
//	if (parrentNode != NULL){
//		ptr = Ov_StaticPtrCast(ov_domain, opcua_nodeStoreFunctions_resolveNodeIdToOvObject(parrentNode));
//		if (ptr == NULL)
//			ptr = Ov_StaticPtrCast(ov_domain, Ov_SearchChild(ov_containment, &pdb->root, "TechUnits"));
//	}else
		ptr = Ov_StaticPtrCast(ov_domain, Ov_SearchChild(ov_containment, &pdb->root, "TechUnits"));
	OV_STRING tmpString = NULL;
	ov_string_print(&tmpString, "%u", opcuaNode->nodeId.identifier.numeric);
	*ovNode = NULL;
	result = Ov_CreateObject(opcua_variableNode, *ovNode, ptr, tmpString);
	if (*ovNode == NULL)
		return result;

	copyOPCUAQualifiedNameToOV	(&opcuaNode->browseName	, &(*ovNode)->p_browseName);
	copyOPCUALocalizedTextToOV	(&opcuaNode->description, &(*ovNode)->p_description);
	copyOPCUALocalizedTextToOV	(&opcuaNode->displayName, &(*ovNode)->p_displayName);
	copyOPCUANodeIdToOV			(&opcuaNode->nodeId		, &(*ovNode)->p_nodeId);


	(*ovNode)->v_nodeClass 		= opcuaNode->nodeClass;
	//(*ovNode)->v_userWriteMask 	= opcuaNode->userWriteMask;
	(*ovNode)->v_writeMask 		= opcuaNode->writeMask;

	//copy references to ov node structure
	OV_INSTPTR_opcua_reference tmpRefNode = NULL;
	for (size_t i = 0; i < opcuaNode->referencesSize; i++){
		ov_string_print(&tmpString, "Reference%u:%u", opcuaNode->references[i].referenceTypeId.identifier.numeric, opcuaNode->references[i].targetId.nodeId.identifier.numeric);
		result = createOpcuaReferenceNode(Ov_StaticPtrCast(ov_domain, &(*ovNode)->p_references), &tmpRefNode, tmpString);
		if (tmpRefNode == NULL)
			return result;
		copyOPCUAReferenceNodeToOV(&opcuaNode->references[i], tmpRefNode);
	}
	//variable related fields
	(*ovNode)->v_valuerank 				= opcuaNode->valueRank;
	(*ovNode)->v_arrayDimensionsSize 	= opcuaNode->arrayDimensionsSize;
	result = Ov_SetDynamicVectorLength(&(*ovNode)->v_arrayDimensions, opcuaNode->arrayDimensionsSize, UINT);
	if (result != 0)
		return result;
	for (size_t i = 0; i < opcuaNode->arrayDimensionsSize; i++){
		(*ovNode)->v_arrayDimensions.value[i] = opcuaNode->arrayDimensions[i];
	}
	(*ovNode)->v_valueSource 				= opcuaNode->valueSource;
	(*ovNode)->v_accessLevel 				= opcuaNode->accessLevel;
	//(*ovNode)->v_userAccessLevel 			= opcuaNode->userAccessLevel;
	(*ovNode)->v_minimumSamplingInterval	= opcuaNode->minimumSamplingInterval;
	(*ovNode)->v_historizing 				= opcuaNode->historizing;
	copyOPCUANodeIdToOV	(&opcuaNode->dataType, &(*ovNode)->p_dataType);

	if ((*ovNode)->v_arrayDimensionsSize == 0 && opcuaNode->value.data.value.value.type != NULL){
		switch(opcuaNode->value.data.value.value.type->typeIndex){
		case UA_TYPES_BOOLEAN:
			(*ovNode)->v_value.value.vartype = OV_VT_BOOL;
			(*ovNode)->v_value.value.valueunion.val_bool = *((UA_Boolean*)opcuaNode->value.data.value.value.data);
			break;
		case UA_TYPES_BYTE:
			(*ovNode)->v_value.value.vartype = OV_VT_BYTE;
			(*ovNode)->v_value.value.valueunion.val_byte = *((UA_Byte*)opcuaNode->value.data.value.value.data);
			break;
		case UA_TYPES_INT32:
			(*ovNode)->v_value.value.vartype = OV_VT_INT;
			(*ovNode)->v_value.value.valueunion.val_int = *((UA_Int32*)opcuaNode->value.data.value.value.data);
			break;
		case UA_TYPES_UINT32:
			(*ovNode)->v_value.value.vartype = OV_VT_UINT;
			(*ovNode)->v_value.value.valueunion.val_uint = *((UA_UInt32*)opcuaNode->value.data.value.value.data);
			break;
		case UA_TYPES_FLOAT:
			(*ovNode)->v_value.value.vartype = OV_VT_SINGLE;
			(*ovNode)->v_value.value.valueunion.val_single = *((UA_Float*)opcuaNode->value.data.value.value.data);
			break;
		case UA_TYPES_DOUBLE:
			(*ovNode)->v_value.value.vartype = OV_VT_DOUBLE;
			(*ovNode)->v_value.value.valueunion.val_double = *((UA_Double*)opcuaNode->value.data.value.value.data);
			break;
		case UA_TYPES_STRING:
			(*ovNode)->v_value.value.vartype = OV_VT_STRING;
			copyOPCUAStringToOV(*((UA_String*)opcuaNode->value.data.value.value.data),
									&((*ovNode)->v_value.value.valueunion.val_string));
			break;
		default:
			break;
		}
	}else if ((*ovNode)->v_arrayDimensionsSize == 1 && opcuaNode->value.data.value.value.type != NULL){
		switch(opcuaNode->value.data.value.value.type->typeIndex){
			case UA_TYPES_BOOLEAN:
				(*ovNode)->v_value.value.vartype = OV_VT_BOOL_VEC;
				Ov_SetDynamicVectorLength(&(*ovNode)->v_value.value.valueunion.val_bool_vec, opcuaNode->arrayDimensions[0], BOOL);
				for (size_t i = 0; i < opcuaNode->arrayDimensions[0]; i++){
					(*ovNode)->v_value.value.valueunion.val_bool_vec.value[i] = *(((UA_Boolean*)opcuaNode->value.data.value.value.data)+i);
				}
				break;
			case UA_TYPES_BYTE:
				(*ovNode)->v_value.value.vartype = OV_VT_BYTE_VEC;
				Ov_SetDynamicVectorLength(&(*ovNode)->v_value.value.valueunion.val_byte_vec, opcuaNode->arrayDimensions[0], BYTE);
				for (size_t i = 0; i < opcuaNode->arrayDimensions[0]; i++){
					(*ovNode)->v_value.value.valueunion.val_byte_vec.value[i] = *(((UA_Byte*)opcuaNode->value.data.value.value.data)+i);
				}
				break;
			case UA_TYPES_INT32:
				(*ovNode)->v_value.value.vartype = OV_VT_INT_VEC;
				Ov_SetDynamicVectorLength(&(*ovNode)->v_value.value.valueunion.val_int_vec, opcuaNode->arrayDimensions[0], INT);
				for (size_t i = 0; i < opcuaNode->arrayDimensions[0]; i++){
					(*ovNode)->v_value.value.valueunion.val_int_vec.value[i] = *(((UA_Int32*)opcuaNode->value.data.value.value.data)+i);
				}
				break;
			case UA_TYPES_UINT32:
				(*ovNode)->v_value.value.vartype = OV_VT_UINT_VEC;
				Ov_SetDynamicVectorLength(&(*ovNode)->v_value.value.valueunion.val_uint_vec, opcuaNode->arrayDimensions[0], UINT);
				for (size_t i = 0; i < opcuaNode->arrayDimensions[0]; i++){
					(*ovNode)->v_value.value.valueunion.val_uint_vec.value[i] = *(((UA_UInt32*)opcuaNode->value.data.value.value.data)+i);
				}
				break;
			case UA_TYPES_FLOAT:
				(*ovNode)->v_value.value.vartype = OV_VT_SINGLE_VEC;
				Ov_SetDynamicVectorLength(&(*ovNode)->v_value.value.valueunion.val_single_vec, opcuaNode->arrayDimensions[0], SINGLE);
				for (size_t i = 0; i < opcuaNode->arrayDimensions[0]; i++){
					(*ovNode)->v_value.value.valueunion.val_single_vec.value[i] = *(((UA_Float*)opcuaNode->value.data.value.value.data)+i);
				}
				break;
			case UA_TYPES_DOUBLE:
				(*ovNode)->v_value.value.vartype = OV_VT_DOUBLE_VEC;
				Ov_SetDynamicVectorLength(&(*ovNode)->v_value.value.valueunion.val_double_vec, opcuaNode->arrayDimensions[0], DOUBLE);
				for (size_t i = 0; i < opcuaNode->arrayDimensions[0]; i++){
					(*ovNode)->v_value.value.valueunion.val_double_vec.value[i] = *(((UA_Double*)opcuaNode->value.data.value.value.data)+i);
				}
				break;
			case UA_TYPES_STRING:
				(*ovNode)->v_value.value.vartype = OV_VT_STRING_VEC;
				Ov_SetDynamicVectorLength(&(*ovNode)->v_value.value.valueunion.val_string_vec, opcuaNode->arrayDimensions[0], STRING);
				for (size_t i = 0; i < opcuaNode->arrayDimensions[0]; i++){
					copyOPCUAStringToOV(*((UA_String*)(opcuaNode->value.data.value.value.data)+i),
															&((*ovNode)->v_value.value.valueunion.val_string_vec.value[i]));
				}
				break;
			default:
				break;
			}
	}else{

	}

	return result;
}

