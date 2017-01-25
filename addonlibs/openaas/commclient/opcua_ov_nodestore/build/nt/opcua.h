/*
*   This file was generated by the ACPLT/OV C-Code Generator.
*
*   C-Code Generator version: 1.6.4
*   ACPLT/OV library version: 2.0.0
*   Date of file generation:   9-Nov-2016 (13:33:19)
*
*   DO NOT EDIT THIS FILE!
*/

#ifndef OV_LIBRARY_opcua_H_INCLUDED
#define OV_LIBRARY_opcua_H_INCLUDED

#include "libov/ov_library.h"
#include "libov/ov_structure.h"
#include "libov/ov_class.h"
#include "libov/ov_association.h"
#include "libov/ov_variable.h"
#include "libov/ov_part.h"
#include "libov/ov_operation.h"
#include "ov.h"
#include "ksbase.h"
#include "fb.h"

#include "opcua.ovt"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef OV_COMPILE_LIBRARY_opcua
#if OV_COMPILER_BORLAND
#define OV_VAREXTERN extern
#else
#define OV_VAREXTERN OV_DLLVAREXPORT
#endif
#define OV_FNCEXTERN OV_DLLFNCEXPORT
#else
#define OV_VAREXTERN OV_DLLVARIMPORT
#define OV_FNCEXTERN OV_DLLVARIMPORT
#endif

#define OV_PPT_opcua_networkLayerToConnection struct OV_INST_opcua_ovNetworkLayer*
#define OV_CPT_opcua_networkLayerToConnection struct OV_INST_opcua_uaConnection*
#define OV_PCI_opcua_networkLayerToConnection is_of_class_opcua_ovNetworkLayer
#define OV_CCI_opcua_networkLayerToConnection is_of_class_opcua_uaConnection

#define OV_BIPT_opcua_uaServer OV_INSTPTR_ksbase_ComTask
#define OV_BVPT_opcua_uaServer OV_VTBLPTR_ksbase_ComTask

#define OV_INSTBODY_opcua_uaServer \
    OV_INSTBODY_ksbase_ComTask \
    OV_UINT v_NameSpaceIndex; \
    OV_BOOL v_LoginEnableAnonymous; \
    OV_BOOL v_LoginEnableUsernamePassword; \
    OV_STRING_VEC v_LoginUsernames; \
    OV_STRING_VEC v_LoginPasswords; \
    OV_STRING v_ApplicationURI; \
    OV_STRING v_ApplicationName; \
    UA_ServerConfig v_serverConfig; \
    OV_PTR_UA_Server v_serverData; \
    UA_ServerNetworkLayer v_networkLayerOv;

#define OV_CIB_opcua_uaServer \
    OV_CIB_ksbase_ComTask \
    int is_of_class_opcua_uaServer:1;

#define OV_STATICINSTBODY_opcua_uaServer

#define OV_BIPT_opcua_uaIdentificator OV_INSTPTR_ksbase_ProtocolIdentificator
#define OV_BVPT_opcua_uaIdentificator OV_VTBLPTR_ksbase_ProtocolIdentificator

#define OV_INSTBODY_opcua_uaIdentificator \
    OV_INSTBODY_ksbase_ProtocolIdentificator \
    OV_STRING v_ident; \
    OV_UINT v_msgMinSize; \
    OV_UINT v_highestOPCVersion;

#define OV_CIB_opcua_uaIdentificator \
    OV_CIB_ksbase_ProtocolIdentificator \
    int is_of_class_opcua_uaIdentificator:1;

#define OV_STATICINSTBODY_opcua_uaIdentificator

#define OV_BIPT_opcua_uaConnection OV_INSTPTR_ksbase_ClientHandler
#define OV_BVPT_opcua_uaConnection OV_VTBLPTR_ksbase_ClientHandler

#define OV_INSTBODY_opcua_uaConnection \
    OV_INSTBODY_ksbase_ClientHandler \
    UA_ConnectionPTR v_connection; \
    OV_BOOL v_workNext; \
    KS_DATAPACKET v_buffer;

#define OV_CIB_opcua_uaConnection \
    OV_CIB_ksbase_ClientHandler \
    int is_of_class_opcua_uaConnection:1;

#define OV_STATICINSTBODY_opcua_uaConnection

#define OV_BIPT_opcua_ovNetworkLayer OV_INSTPTR_ov_object
#define OV_BVPT_opcua_ovNetworkLayer OV_VTBLPTR_ov_object

#define OV_INSTBODY_opcua_ovNetworkLayer \
    OV_INSTBODY_ov_object \
    UA_String v_discoveryUrlInternal; \
    UA_ConnectionConfig v_localConfig; \
    UA_ConnectionPTRPTR v_connsToClose; \
    OV_UINT v_connsToCloseCount;

#define OV_CIB_opcua_ovNetworkLayer \
    OV_CIB_ov_object \
    int is_of_class_opcua_ovNetworkLayer:1;

#define OV_STATICINSTBODY_opcua_ovNetworkLayer

#define OV_BIPT_opcua_uaSimpleTicketAuthenticator OV_INSTPTR_ksbase_TicketAuthenticator
#define OV_BVPT_opcua_uaSimpleTicketAuthenticator OV_VTBLPTR_ksbase_TicketAuthenticator

#define OV_INSTBODY_opcua_uaSimpleTicketAuthenticator \
    OV_INSTBODY_ksbase_TicketAuthenticator

#define OV_CIB_opcua_uaSimpleTicketAuthenticator \
    OV_CIB_ksbase_TicketAuthenticator \
    int is_of_class_opcua_uaSimpleTicketAuthenticator:1;

#define OV_STATICINSTBODY_opcua_uaSimpleTicketAuthenticator

#define OV_BIPT_opcua_nodeStoreFunctions OV_INSTPTR_ov_object
#define OV_BVPT_opcua_nodeStoreFunctions OV_VTBLPTR_ov_object

#define OV_INSTBODY_opcua_nodeStoreFunctions \
    OV_INSTBODY_ov_object

#define OV_CIB_opcua_nodeStoreFunctions \
    OV_CIB_ov_object \
    int is_of_class_opcua_nodeStoreFunctions:1;

#define OV_STATICINSTBODY_opcua_nodeStoreFunctions

#define OV_BIPT_opcua_arguments OV_INSTPTR_ov_object
#define OV_BVPT_opcua_arguments OV_VTBLPTR_ov_object

#define OV_INSTBODY_opcua_arguments \
    OV_INSTBODY_ov_object \
    OV_STRING_VEC v_Names; \
    OV_INT_VEC v_Types; \
    OV_BOOL_VEC v_isArray; \
    OV_UINT_VEC v_Lengths; \
    OV_STRING_VEC v_Descriptions;

#define OV_CIB_opcua_arguments \
    OV_CIB_ov_object \
    int is_of_class_opcua_arguments:1;

#define OV_STATICINSTBODY_opcua_arguments

#define OV_BIPT_opcua_methodNode OV_INSTPTR_ov_domain
#define OV_BVPT_opcua_methodNode OV_VTBLPTR_ov_domain

#define OV_INSTBODY_opcua_methodNode \
    OV_INSTBODY_ov_domain \
    OV_BOOL v_callable; \
    OV_INST_opcua_arguments p_InputArguments; \
    OV_INST_opcua_arguments p_OutputArguments;

#define OV_CIB_opcua_methodNode \
    OV_CIB_ov_domain \
    int is_of_class_opcua_methodNode:1;

#define OV_STATICINSTBODY_opcua_methodNode

#define OV_BIPT_opcua_getServerconfig OV_INSTPTR_opcua_methodNode
#define OV_BVPT_opcua_getServerconfig OV_VTBLPTR_opcua_methodNode

#define OV_INSTBODY_opcua_getServerconfig \
    OV_INSTBODY_opcua_methodNode

#define OV_CIB_opcua_getServerconfig \
    OV_CIB_opcua_methodNode \
    int is_of_class_opcua_getServerconfig:1;

#define OV_STATICINSTBODY_opcua_getServerconfig

#define OV_BIPT_opcua_setServerconfig OV_INSTPTR_opcua_methodNode
#define OV_BVPT_opcua_setServerconfig OV_VTBLPTR_opcua_methodNode

#define OV_INSTBODY_opcua_setServerconfig \
    OV_INSTBODY_opcua_methodNode

#define OV_CIB_opcua_setServerconfig \
    OV_CIB_opcua_methodNode \
    int is_of_class_opcua_setServerconfig:1;

#define OV_STATICINSTBODY_opcua_setServerconfig

#define OV_BIPT_opcua_shutDown OV_INSTPTR_opcua_methodNode
#define OV_BVPT_opcua_shutDown OV_VTBLPTR_opcua_methodNode

#define OV_INSTBODY_opcua_shutDown \
    OV_INSTBODY_opcua_methodNode

#define OV_CIB_opcua_shutDown \
    OV_CIB_opcua_methodNode \
    int is_of_class_opcua_shutDown:1;

#define OV_STATICINSTBODY_opcua_shutDown

#define OV_BIPT_opcua_nodeId OV_INSTPTR_ov_domain
#define OV_BVPT_opcua_nodeId OV_VTBLPTR_ov_domain

#define OV_INSTBODY_opcua_nodeId \
    OV_INSTBODY_ov_domain \
    OV_ANY v_id; \
    OV_UINT v_namespaceIndex; \
    OV_INT v_identifierType;

#define OV_CIB_opcua_nodeId \
    OV_CIB_ov_domain \
    int is_of_class_opcua_nodeId:1;

#define OV_STATICINSTBODY_opcua_nodeId

#define OV_BIPT_opcua_expandedNodeId OV_INSTPTR_ov_domain
#define OV_BVPT_opcua_expandedNodeId OV_VTBLPTR_ov_domain

#define OV_INSTBODY_opcua_expandedNodeId \
    OV_INSTBODY_ov_domain \
    OV_STRING v_namespaceUri; \
    OV_UINT v_serverIndex; \
    OV_INST_opcua_nodeId p_nodeId;

#define OV_CIB_opcua_expandedNodeId \
    OV_CIB_ov_domain \
    int is_of_class_opcua_expandedNodeId:1;

#define OV_STATICINSTBODY_opcua_expandedNodeId

#define OV_BIPT_opcua_qualifiedName OV_INSTPTR_ov_domain
#define OV_BVPT_opcua_qualifiedName OV_VTBLPTR_ov_domain

#define OV_INSTBODY_opcua_qualifiedName \
    OV_INSTBODY_ov_domain \
    OV_STRING v_name; \
    OV_UINT v_namespaceIndex;

#define OV_CIB_opcua_qualifiedName \
    OV_CIB_ov_domain \
    int is_of_class_opcua_qualifiedName:1;

#define OV_STATICINSTBODY_opcua_qualifiedName

#define OV_BIPT_opcua_localizedText OV_INSTPTR_ov_domain
#define OV_BVPT_opcua_localizedText OV_VTBLPTR_ov_domain

#define OV_INSTBODY_opcua_localizedText \
    OV_INSTBODY_ov_domain \
    OV_STRING v_locale; \
    OV_STRING v_text;

#define OV_CIB_opcua_localizedText \
    OV_CIB_ov_domain \
    int is_of_class_opcua_localizedText:1;

#define OV_STATICINSTBODY_opcua_localizedText

#define OV_BIPT_opcua_extensionObject OV_INSTPTR_ov_domain
#define OV_BVPT_opcua_extensionObject OV_VTBLPTR_ov_domain

#define OV_INSTBODY_opcua_extensionObject \
    OV_INSTBODY_ov_domain \
    OV_STRING v_locale; \
    OV_STRING v_text;

#define OV_CIB_opcua_extensionObject \
    OV_CIB_ov_domain \
    int is_of_class_opcua_extensionObject:1;

#define OV_STATICINSTBODY_opcua_extensionObject

#define OV_BIPT_opcua_variant OV_INSTPTR_ov_domain
#define OV_BVPT_opcua_variant OV_VTBLPTR_ov_domain

#define OV_INSTBODY_opcua_variant \
    OV_INSTBODY_ov_domain \
    OV_STRING v_locale; \
    OV_STRING v_text;

#define OV_CIB_opcua_variant \
    OV_CIB_ov_domain \
    int is_of_class_opcua_variant:1;

#define OV_STATICINSTBODY_opcua_variant

#define OV_BIPT_opcua_dataValue OV_INSTPTR_ov_domain
#define OV_BVPT_opcua_dataValue OV_VTBLPTR_ov_domain

#define OV_INSTBODY_opcua_dataValue \
    OV_INSTBODY_ov_domain \
    OV_UINT v_encodingMask; \
    OV_UINT v_status; \
    OV_INT v_sourceTimestamp; \
    OV_UINT v_sourcePicoseconds; \
    OV_INT v_serverTimestamp; \
    OV_UINT v_serverPicoseconds; \
    OV_INST_opcua_variant p_value;

#define OV_CIB_opcua_dataValue \
    OV_CIB_ov_domain \
    int is_of_class_opcua_dataValue:1;

#define OV_STATICINSTBODY_opcua_dataValue

#define OV_BIPT_opcua_diagnosticInfo OV_INSTPTR_ov_domain
#define OV_BVPT_opcua_diagnosticInfo OV_VTBLPTR_ov_domain

#define OV_INSTBODY_opcua_diagnosticInfo \
    OV_INSTBODY_ov_domain \
    OV_STRING v_locale; \
    OV_STRING v_text;

#define OV_CIB_opcua_diagnosticInfo \
    OV_CIB_ov_domain \
    int is_of_class_opcua_diagnosticInfo:1;

#define OV_STATICINSTBODY_opcua_diagnosticInfo

#define OV_BIPT_opcua_baseNode OV_INSTPTR_ov_domain
#define OV_BVPT_opcua_baseNode OV_VTBLPTR_ov_domain

#define OV_INSTBODY_opcua_baseNode \
    OV_INSTBODY_ov_domain \
    OV_UINT v_nodeClass; \
    OV_UINT v_writeMask; \
    OV_UINT v_userWriteMask; \
    OV_INST_opcua_nodeId p_nodeId; \
    OV_INST_opcua_qualifiedName p_browseName; \
    OV_INST_opcua_localizedText p_description; \
    OV_INST_opcua_localizedText p_displayName; \
    OV_INST_ov_domain p_references;

#define OV_CIB_opcua_baseNode \
    OV_CIB_ov_domain \
    int is_of_class_opcua_baseNode:1;

#define OV_STATICINSTBODY_opcua_baseNode

#define OV_BIPT_opcua_variableNode OV_INSTPTR_opcua_baseNode
#define OV_BVPT_opcua_variableNode OV_VTBLPTR_opcua_baseNode

#define OV_INSTBODY_opcua_variableNode \
    OV_INSTBODY_opcua_baseNode \
    OV_INT v_valuerank; \
    OV_UINT v_arrayDimensionsSize; \
    OV_UINT_VEC v_arrayDimensions; \
    OV_ANY v_value;

#define OV_CIB_opcua_variableNode \
    OV_CIB_opcua_baseNode \
    int is_of_class_opcua_variableNode:1;

#define OV_STATICINSTBODY_opcua_variableNode

#define OV_BIPT_opcua_variableTypeNode OV_INSTPTR_opcua_variableNode
#define OV_BVPT_opcua_variableTypeNode OV_VTBLPTR_opcua_variableNode

#define OV_INSTBODY_opcua_variableTypeNode \
    OV_INSTBODY_opcua_variableNode \
    OV_BOOL v_isAbstract; \
    OV_INT v_accessLevel; \
    OV_INT v_userAccessLevel; \
    OV_DOUBLE v_minimumSamplingInterval; \
    OV_BOOL v_historizing;

#define OV_CIB_opcua_variableTypeNode \
    OV_CIB_opcua_variableNode \
    int is_of_class_opcua_variableTypeNode:1;

#define OV_STATICINSTBODY_opcua_variableTypeNode

#define OV_BIPT_opcua_objectNode OV_INSTPTR_opcua_baseNode
#define OV_BVPT_opcua_objectNode OV_VTBLPTR_opcua_baseNode

#define OV_INSTBODY_opcua_objectNode \
    OV_INSTBODY_opcua_baseNode \
    OV_INT v_eventNotifier;

#define OV_CIB_opcua_objectNode \
    OV_CIB_opcua_baseNode \
    int is_of_class_opcua_objectNode:1;

#define OV_STATICINSTBODY_opcua_objectNode

#define OV_BIPT_opcua_objectTypeNode OV_INSTPTR_opcua_objectNode
#define OV_BVPT_opcua_objectTypeNode OV_VTBLPTR_opcua_objectNode

#define OV_INSTBODY_opcua_objectTypeNode \
    OV_INSTBODY_opcua_objectNode \
    OV_BOOL v_isAbstract;

#define OV_CIB_opcua_objectTypeNode \
    OV_CIB_opcua_objectNode \
    int is_of_class_opcua_objectTypeNode:1;

#define OV_STATICINSTBODY_opcua_objectTypeNode

#define OV_BIPT_opcua_referenceTypeNode OV_INSTPTR_opcua_baseNode
#define OV_BVPT_opcua_referenceTypeNode OV_VTBLPTR_opcua_baseNode

#define OV_INSTBODY_opcua_referenceTypeNode \
    OV_INSTBODY_opcua_baseNode \
    OV_BOOL v_isAbstract; \
    OV_BOOL v_symmetric; \
    OV_INST_opcua_localizedText p_inverseName;

#define OV_CIB_opcua_referenceTypeNode \
    OV_CIB_opcua_baseNode \
    int is_of_class_opcua_referenceTypeNode:1;

#define OV_STATICINSTBODY_opcua_referenceTypeNode

#define OV_BIPT_opcua_reference OV_INSTPTR_ov_domain
#define OV_BVPT_opcua_reference OV_VTBLPTR_ov_domain

#define OV_INSTBODY_opcua_reference \
    OV_INSTBODY_ov_domain \
    OV_BOOL v_isInverse; \
    OV_INST_opcua_nodeId p_referenceTypeNodeId; \
    OV_INST_opcua_expandedNodeId p_targetNodeId;

#define OV_CIB_opcua_reference \
    OV_CIB_ov_domain \
    int is_of_class_opcua_reference:1;

#define OV_STATICINSTBODY_opcua_reference

#define OV_BIPT_opcua_dataTypeNode OV_INSTPTR_opcua_baseNode
#define OV_BVPT_opcua_dataTypeNode OV_VTBLPTR_opcua_baseNode

#define OV_INSTBODY_opcua_dataTypeNode \
    OV_INSTBODY_opcua_baseNode \
    OV_BOOL v_isAbstract;

#define OV_CIB_opcua_dataTypeNode \
    OV_CIB_opcua_baseNode \
    int is_of_class_opcua_dataTypeNode:1;

#define OV_STATICINSTBODY_opcua_dataTypeNode

#define OV_BIPT_opcua_viewNode OV_INSTPTR_opcua_baseNode
#define OV_BVPT_opcua_viewNode OV_VTBLPTR_opcua_baseNode

#define OV_INSTBODY_opcua_viewNode \
    OV_INSTBODY_opcua_baseNode \
    OV_INT v_eventNotifier; \
    OV_BOOL v_containNoLoops;

#define OV_CIB_opcua_viewNode \
    OV_CIB_opcua_baseNode \
    int is_of_class_opcua_viewNode:1;

#define OV_STATICINSTBODY_opcua_viewNode

#define OV_BIPT_opcua_testObject OV_INSTPTR_fb_functionblock
#define OV_BVPT_opcua_testObject OV_VTBLPTR_fb_functionblock

#define OV_INSTBODY_opcua_testObject \
    OV_INSTBODY_fb_functionblock \
    OV_INT v_var1;

#define OV_CIB_opcua_testObject \
    OV_CIB_fb_functionblock \
    int is_of_class_opcua_testObject:1;

#define OV_STATICINSTBODY_opcua_testObject

OV_TYPEDEF_INSTANCE(opcua_uaServer);
OV_TYPEDEF_INSTANCE(opcua_uaIdentificator);
OV_TYPEDEF_INSTANCE(opcua_uaConnection);
OV_TYPEDEF_INSTANCE(opcua_ovNetworkLayer);
OV_TYPEDEF_INSTANCE(opcua_uaSimpleTicketAuthenticator);
OV_TYPEDEF_INSTANCE(opcua_nodeStoreFunctions);
OV_TYPEDEF_INSTANCE(opcua_arguments);
OV_TYPEDEF_INSTANCE(opcua_methodNode);
OV_TYPEDEF_INSTANCE(opcua_getServerconfig);
OV_TYPEDEF_INSTANCE(opcua_setServerconfig);
OV_TYPEDEF_INSTANCE(opcua_shutDown);
OV_TYPEDEF_INSTANCE(opcua_nodeId);
OV_TYPEDEF_INSTANCE(opcua_expandedNodeId);
OV_TYPEDEF_INSTANCE(opcua_qualifiedName);
OV_TYPEDEF_INSTANCE(opcua_localizedText);
OV_TYPEDEF_INSTANCE(opcua_extensionObject);
OV_TYPEDEF_INSTANCE(opcua_variant);
OV_TYPEDEF_INSTANCE(opcua_dataValue);
OV_TYPEDEF_INSTANCE(opcua_diagnosticInfo);
OV_TYPEDEF_INSTANCE(opcua_baseNode);
OV_TYPEDEF_INSTANCE(opcua_variableNode);
OV_TYPEDEF_INSTANCE(opcua_variableTypeNode);
OV_TYPEDEF_INSTANCE(opcua_objectNode);
OV_TYPEDEF_INSTANCE(opcua_objectTypeNode);
OV_TYPEDEF_INSTANCE(opcua_referenceTypeNode);
OV_TYPEDEF_INSTANCE(opcua_reference);
OV_TYPEDEF_INSTANCE(opcua_dataTypeNode);
OV_TYPEDEF_INSTANCE(opcua_viewNode);
OV_TYPEDEF_INSTANCE(opcua_testObject);

#include "opcua.ovf"

OV_FNCEXTERN OV_FNC_CONSTRUCTOR opcua_uaServer_constructor;
OV_FNCEXTERN OV_FNC_DESTRUCTOR opcua_uaServer_destructor;
OV_FNCEXTERN OV_FNC_STARTUP opcua_uaServer_startup;
OV_FNCEXTERN OV_FNC_SHUTDOWN opcua_uaServer_shutdown;
OV_FNCEXTERN OV_FNC_GETACCESS opcua_uaServer_getaccess;
OV_FNCEXTERN KSBASE_FNC_TYPEMETHOD opcua_uaServer_typemethod;

OV_FNCEXTERN OV_FNC_CONSTRUCTOR opcua_uaIdentificator_constructor;
OV_FNCEXTERN KSBASE_FNC_IDENTIFY opcua_uaIdentificator_identify;
OV_FNCEXTERN KSBASE_FNC_CREATECH opcua_uaIdentificator_createClientHandler;

OV_FNCEXTERN OV_FNC_CONSTRUCTOR opcua_uaConnection_constructor;
OV_FNCEXTERN OV_FNC_DESTRUCTOR opcua_uaConnection_destructor;
OV_FNCEXTERN OV_FNC_STARTUP opcua_uaConnection_startup;
OV_FNCEXTERN OV_FNC_SHUTDOWN opcua_uaConnection_shutdown;
OV_FNCEXTERN KSBASE_FNC_HANDLEREQUEST opcua_uaConnection_HandleRequest;
OV_FNCEXTERN KSBASE_FNC_TYPEMETHOD opcua_uaConnection_typemethod;

OV_FNCEXTERN OV_FNC_CONSTRUCTOR opcua_ovNetworkLayer_constructor;
OV_FNCEXTERN OV_FNC_DESTRUCTOR opcua_ovNetworkLayer_destructor;
OV_FNCEXTERN OV_FNC_STARTUP opcua_ovNetworkLayer_startup;
OV_FNCEXTERN OV_FNC_SHUTDOWN opcua_ovNetworkLayer_shutdown;
OV_FNCEXTERN OV_FNC_GETACCESS opcua_ovNetworkLayer_getaccess;
OV_FNCEXTERN UA_FNC_STARTNL opcua_ovNetworkLayer_start;
OV_FNCEXTERN UA_FNC_NLGETWORK opcua_ovNetworkLayer_getJobs;
OV_FNCEXTERN UA_FNC_STOPNL opcua_ovNetworkLayer_stop;
OV_FNCEXTERN UA_FNC_DELETENL opcua_ovNetworkLayer_delete;

OV_FNCEXTERN OV_FNC_CONSTRUCTOR opcua_uaSimpleTicketAuthenticator_constructor;
OV_FNCEXTERN OV_FNC_STARTUP opcua_uaSimpleTicketAuthenticator_startup;
OV_FNCEXTERN OV_FNC_SHUTDOWN opcua_uaSimpleTicketAuthenticator_shutdown;
OV_FNCEXTERN KSBASE_FNC_CREATETICKET opcua_uaSimpleTicketAuthenticator_createticket;
OV_FNCEXTERN KSBASE_FNC_DELETETICKET opcua_uaSimpleTicketAuthenticator_deleteticket;
OV_FNCEXTERN KSBASE_FNC_ENCODEREPLY opcua_uaSimpleTicketAuthenticator_encodereply;
OV_FNCEXTERN KSBASE_FNC_GETACCESS opcua_uaSimpleTicketAuthenticator_TicketGetaccess;

OV_FNCEXTERN UA_FNC_OVBASENODETOOPCUA opcua_nodeStoreFunctions_ovBaseNodeToOPCUA;
OV_FNCEXTERN UA_FNC_OVOBJECTNODETOOPCUA opcua_nodeStoreFunctions_ovObjectNodeToOPCUA;
OV_FNCEXTERN UA_FNC_OVOBJECTTYPENODETOOPCUA opcua_nodeStoreFunctions_ovObjectTypeNodeToOPCUA;
OV_FNCEXTERN UA_FNC_OVVARIABLENODETOOPCUA opcua_nodeStoreFunctions_ovVariableNodeToOPCUA;
OV_FNCEXTERN UA_FNC_OPCUABASENODETOOV opcua_nodeStoreFunctions_opcuaBaseNodeToOv;
OV_FNCEXTERN UA_FNC_OPCUAOBJECTNODETOOV opcua_nodeStoreFunctions_opcuaObjectNodeToOv;
OV_FNCEXTERN UA_FNC_OPCUAOBJECTTYPENODETOOV opcua_nodeStoreFunctions_opcuaObjectTypeNodeToOv;
OV_FNCEXTERN UA_FNC_OPCUAVARIABLENODETOOV opcua_nodeStoreFunctions_opcuaVariableNodeToOv;
OV_FNCEXTERN UA_FNC_ADDREFERENCES opcua_nodeStoreFunctions_addReferences;
OV_FNCEXTERN UA_FNC_ADDONEWAYREFERENCE opcua_nodeStoreFunctions_addOneWayReference;
OV_FNCEXTERN UA_FNC_DELETENODES opcua_nodeStoreFunctions_deleteNodes;
OV_FNCEXTERN UA_FNC_DELETEREFERENCES opcua_nodeStoreFunctions_deleteReferences;
OV_FNCEXTERN UA_FNC_READNODES opcua_nodeStoreFunctions_readNodes;
OV_FNCEXTERN UA_FNC_WRITENODES opcua_nodeStoreFunctions_writeNodes;
OV_FNCEXTERN UA_FNC_BROWSENODES opcua_nodeStoreFunctions_browseNodes;
OV_FNCEXTERN UA_FNC_TRANSLATEBROWSEPATHSTONODEIDS opcua_nodeStoreFunctions_translateBrowsePathsToNodeIDs;
OV_FNCEXTERN UA_FNC_CALL opcua_nodeStoreFunctions_call;
OV_FNCEXTERN UA_FNC_PACKARGS opcua_nodeStoreFunctions_packCallArgs;
OV_FNCEXTERN UA_FNC_UNPACKARGS opcua_nodeStoreFunctions_unpackCallArgs;
OV_FNCEXTERN UA_FNC_GETCALLARGS opcua_nodeStoreFunctions_getCallArgs;
OV_FNCEXTERN UA_FNC_SETCALLARGS opcua_nodeStoreFunctions_setCallArgs;

OV_FNCEXTERN OV_FNC_CONSTRUCTOR opcua_arguments_constructor;
OV_FNCEXTERN OV_FNC_GETACCESS opcua_arguments_getaccess;

OV_FNCEXTERN UA_FNC_PRECALLMETHOD opcua_methodNode_preCallMethod;
OV_FNCEXTERN UA_FNC_CALLEDMETHOD opcua_methodNode_calledMethod;
OV_FNCEXTERN UA_FNC_POSTCALLMETHOD opcua_methodNode_postCallMethod;
OV_FNCEXTERN OV_FNC_GETACCESS opcua_methodNode_getaccess;

OV_FNCEXTERN OV_FNC_CONSTRUCTOR opcua_getServerconfig_constructor;
OV_FNCEXTERN UA_FNC_CALLEDMETHOD opcua_getServerconfig_calledMethod;

OV_FNCEXTERN OV_FNC_CONSTRUCTOR opcua_setServerconfig_constructor;
OV_FNCEXTERN UA_FNC_CALLEDMETHOD opcua_setServerconfig_calledMethod;

OV_FNCEXTERN OV_FNC_CONSTRUCTOR opcua_shutDown_constructor;
OV_FNCEXTERN UA_FNC_CALLEDMETHOD opcua_shutDown_calledMethod;

OV_FNCEXTERN OV_FNC_GETACCESS opcua_nodeId_getaccess;

OV_FNCEXTERN OV_FNC_GETACCESS opcua_qualifiedName_getaccess;

OV_FNCEXTERN OV_FNC_GETACCESS opcua_localizedText_getaccess;

OV_FNCEXTERN OV_FNC_GETACCESS opcua_extensionObject_getaccess;

OV_FNCEXTERN OV_FNC_GETACCESS opcua_variant_getaccess;

OV_FNCEXTERN OV_FNC_GETACCESS opcua_dataValue_getaccess;

OV_FNCEXTERN OV_FNC_GETACCESS opcua_diagnosticInfo_getaccess;

OV_FNCEXTERN OV_FNC_GETACCESS opcua_baseNode_getaccess;

OV_FNCEXTERN OV_FNC_CONSTRUCTOR opcua_testObject_constructor;
OV_FNCEXTERN OV_FNC_DESTRUCTOR opcua_testObject_destructor;
OV_FNCEXTERN FB_FNC_TYPEMETHOD opcua_testObject_typemethod;

#define OV_VTBLBODY_opcua_uaServer \
    OV_VTBLBODY_ksbase_ComTask

#define OV_VTBLBODY_opcua_uaIdentificator \
    OV_VTBLBODY_ksbase_ProtocolIdentificator

#define OV_VTBLBODY_opcua_uaConnection \
    OV_VTBLBODY_ksbase_ClientHandler

#define OV_VTBLBODY_opcua_ovNetworkLayer \
    OV_VTBLBODY_ov_object \
    UA_FNC_STARTNL* m_start; \
    UA_FNC_NLGETWORK* m_getJobs; \
    UA_FNC_STOPNL* m_stop; \
    UA_FNC_DELETENL* m_delete;

#define OV_VTBLBODY_opcua_uaSimpleTicketAuthenticator \
    OV_VTBLBODY_ksbase_TicketAuthenticator

#define OV_VTBLBODY_opcua_nodeStoreFunctions \
    OV_VTBLBODY_ov_object \
    UA_FNC_OVBASENODETOOPCUA* m_ovBaseNodeToOPCUA; \
    UA_FNC_OVOBJECTNODETOOPCUA* m_ovObjectNodeToOPCUA; \
    UA_FNC_OVOBJECTTYPENODETOOPCUA* m_ovObjectTypeNodeToOPCUA; \
    UA_FNC_OVVARIABLENODETOOPCUA* m_ovVariableNodeToOPCUA; \
    UA_FNC_OPCUABASENODETOOV* m_opcuaBaseNodeToOv; \
    UA_FNC_OPCUAOBJECTNODETOOV* m_opcuaObjectNodeToOv; \
    UA_FNC_OPCUAOBJECTTYPENODETOOV* m_opcuaObjectTypeNodeToOv; \
    UA_FNC_OPCUAVARIABLENODETOOV* m_opcuaVariableNodeToOv; \
    UA_FNC_ADDREFERENCES* m_addReferences; \
    UA_FNC_ADDONEWAYREFERENCE* m_addOneWayReference; \
    UA_FNC_DELETENODES* m_deleteNodes; \
    UA_FNC_DELETEREFERENCES* m_deleteReferences; \
    UA_FNC_READNODES* m_readNodes; \
    UA_FNC_WRITENODES* m_writeNodes; \
    UA_FNC_BROWSENODES* m_browseNodes; \
    UA_FNC_TRANSLATEBROWSEPATHSTONODEIDS* m_translateBrowsePathsToNodeIDs; \
    UA_FNC_CALL* m_call; \
    UA_FNC_PACKARGS* m_packCallArgs; \
    UA_FNC_UNPACKARGS* m_unpackCallArgs; \
    UA_FNC_GETCALLARGS* m_getCallArgs; \
    UA_FNC_SETCALLARGS* m_setCallArgs;

#define OV_VTBLBODY_opcua_arguments \
    OV_VTBLBODY_ov_object

#define OV_VTBLBODY_opcua_methodNode \
    OV_VTBLBODY_ov_domain \
    UA_FNC_PRECALLMETHOD* m_preCallMethod; \
    UA_FNC_CALLEDMETHOD* m_calledMethod; \
    UA_FNC_POSTCALLMETHOD* m_postCallMethod;

#define OV_VTBLBODY_opcua_getServerconfig \
    OV_VTBLBODY_opcua_methodNode

#define OV_VTBLBODY_opcua_setServerconfig \
    OV_VTBLBODY_opcua_methodNode

#define OV_VTBLBODY_opcua_shutDown \
    OV_VTBLBODY_opcua_methodNode

#define OV_VTBLBODY_opcua_nodeId \
    OV_VTBLBODY_ov_domain

#define OV_VTBLBODY_opcua_expandedNodeId \
    OV_VTBLBODY_ov_domain

#define OV_VTBLBODY_opcua_qualifiedName \
    OV_VTBLBODY_ov_domain

#define OV_VTBLBODY_opcua_localizedText \
    OV_VTBLBODY_ov_domain

#define OV_VTBLBODY_opcua_extensionObject \
    OV_VTBLBODY_ov_domain

#define OV_VTBLBODY_opcua_variant \
    OV_VTBLBODY_ov_domain

#define OV_VTBLBODY_opcua_dataValue \
    OV_VTBLBODY_ov_domain

#define OV_VTBLBODY_opcua_diagnosticInfo \
    OV_VTBLBODY_ov_domain

#define OV_VTBLBODY_opcua_baseNode \
    OV_VTBLBODY_ov_domain

#define OV_VTBLBODY_opcua_variableNode \
    OV_VTBLBODY_opcua_baseNode

#define OV_VTBLBODY_opcua_variableTypeNode \
    OV_VTBLBODY_opcua_variableNode

#define OV_VTBLBODY_opcua_objectNode \
    OV_VTBLBODY_opcua_baseNode

#define OV_VTBLBODY_opcua_objectTypeNode \
    OV_VTBLBODY_opcua_objectNode

#define OV_VTBLBODY_opcua_referenceTypeNode \
    OV_VTBLBODY_opcua_baseNode

#define OV_VTBLBODY_opcua_reference \
    OV_VTBLBODY_ov_domain

#define OV_VTBLBODY_opcua_dataTypeNode \
    OV_VTBLBODY_opcua_baseNode

#define OV_VTBLBODY_opcua_viewNode \
    OV_VTBLBODY_opcua_baseNode

#define OV_VTBLBODY_opcua_testObject \
    OV_VTBLBODY_fb_functionblock

OV_TYPEDEF_VTABLE(opcua_uaServer);
OV_TYPEDEF_VTABLE(opcua_uaIdentificator);
OV_TYPEDEF_VTABLE(opcua_uaConnection);
OV_TYPEDEF_VTABLE(opcua_ovNetworkLayer);
OV_TYPEDEF_VTABLE(opcua_uaSimpleTicketAuthenticator);
OV_TYPEDEF_VTABLE(opcua_nodeStoreFunctions);
OV_TYPEDEF_VTABLE(opcua_arguments);
OV_TYPEDEF_VTABLE(opcua_methodNode);
OV_TYPEDEF_VTABLE(opcua_getServerconfig);
OV_TYPEDEF_VTABLE(opcua_setServerconfig);
OV_TYPEDEF_VTABLE(opcua_shutDown);
OV_TYPEDEF_VTABLE(opcua_nodeId);
OV_TYPEDEF_VTABLE(opcua_expandedNodeId);
OV_TYPEDEF_VTABLE(opcua_qualifiedName);
OV_TYPEDEF_VTABLE(opcua_localizedText);
OV_TYPEDEF_VTABLE(opcua_extensionObject);
OV_TYPEDEF_VTABLE(opcua_variant);
OV_TYPEDEF_VTABLE(opcua_dataValue);
OV_TYPEDEF_VTABLE(opcua_diagnosticInfo);
OV_TYPEDEF_VTABLE(opcua_baseNode);
OV_TYPEDEF_VTABLE(opcua_variableNode);
OV_TYPEDEF_VTABLE(opcua_variableTypeNode);
OV_TYPEDEF_VTABLE(opcua_objectNode);
OV_TYPEDEF_VTABLE(opcua_objectTypeNode);
OV_TYPEDEF_VTABLE(opcua_referenceTypeNode);
OV_TYPEDEF_VTABLE(opcua_reference);
OV_TYPEDEF_VTABLE(opcua_dataTypeNode);
OV_TYPEDEF_VTABLE(opcua_viewNode);
OV_TYPEDEF_VTABLE(opcua_testObject);

OV_DLLFNCEXPORT OV_BOOL opcua_uaServer_LoginEnableAnonymous_get(
    OV_INSTPTR_opcua_uaServer pobj
);

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_LoginEnableAnonymous_set(
    OV_INSTPTR_opcua_uaServer pobj,
    const OV_BOOL value
);

OV_DLLFNCEXPORT OV_BOOL opcua_uaServer_LoginEnableUsernamePassword_get(
    OV_INSTPTR_opcua_uaServer pobj
);

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_LoginEnableUsernamePassword_set(
    OV_INSTPTR_opcua_uaServer pobj,
    const OV_BOOL value
);

OV_DLLFNCEXPORT OV_STRING *opcua_uaServer_LoginUsernames_get(
    OV_INSTPTR_opcua_uaServer pobj,
    OV_UINT *pveclen
);

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_LoginUsernames_set(
    OV_INSTPTR_opcua_uaServer pobj,
    const OV_STRING *pvalue,
    const OV_UINT veclen
);

OV_DLLFNCEXPORT OV_STRING *opcua_uaServer_LoginPasswords_get(
    OV_INSTPTR_opcua_uaServer pobj,
    OV_UINT *pveclen
);

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_LoginPasswords_set(
    OV_INSTPTR_opcua_uaServer pobj,
    const OV_STRING *pvalue,
    const OV_UINT veclen
);

OV_DLLFNCEXPORT OV_UINT opcua_uaServer_LoginLoginsCount_get(
    OV_INSTPTR_opcua_uaServer pobj
);

OV_DLLFNCEXPORT OV_STRING opcua_uaServer_ApplicationURI_get(
    OV_INSTPTR_opcua_uaServer pobj
);

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_ApplicationURI_set(
    OV_INSTPTR_opcua_uaServer pobj,
    const OV_STRING value
);

OV_DLLFNCEXPORT OV_STRING opcua_uaServer_ApplicationName_get(
    OV_INSTPTR_opcua_uaServer pobj
);

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_ApplicationName_set(
    OV_INSTPTR_opcua_uaServer pobj,
    const OV_STRING value
);

OV_DLLFNCEXPORT OV_STRING opcua_ovNetworkLayer_discoveryUrl_get(
    OV_INSTPTR_opcua_ovNetworkLayer pobj
);

OV_DLLFNCEXPORT OV_STRING *opcua_arguments_Names_get(
    OV_INSTPTR_opcua_arguments pobj,
    OV_UINT *pveclen
);

OV_DLLFNCEXPORT OV_INT *opcua_arguments_Types_get(
    OV_INSTPTR_opcua_arguments pobj,
    OV_UINT *pveclen
);

OV_DLLFNCEXPORT OV_BOOL *opcua_arguments_isArray_get(
    OV_INSTPTR_opcua_arguments pobj,
    OV_UINT *pveclen
);

OV_DLLFNCEXPORT OV_UINT *opcua_arguments_Lengths_get(
    OV_INSTPTR_opcua_arguments pobj,
    OV_UINT *pveclen
);

OV_DLLFNCEXPORT OV_STRING *opcua_arguments_Descriptions_get(
    OV_INSTPTR_opcua_arguments pobj,
    OV_UINT *pveclen
);

OV_DECL_LINK(opcua_networkLayerToConnection);
OV_DECL_UNLINK(opcua_networkLayerToConnection);
OV_DECL_GETACCESS(opcua_networkLayerToConnection);

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_uaServer;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_uaServer;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_uaIdentificator;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_uaIdentificator;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_uaConnection;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_uaConnection;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_ovNetworkLayer;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_ovNetworkLayer;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_uaSimpleTicketAuthenticator;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_uaSimpleTicketAuthenticator;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_nodeStoreFunctions;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_nodeStoreFunctions;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_arguments;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_arguments;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_methodNode;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_methodNode;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_getServerconfig;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_getServerconfig;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_setServerconfig;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_setServerconfig;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_shutDown;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_shutDown;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_nodeId;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_nodeId;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_expandedNodeId;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_expandedNodeId;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_qualifiedName;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_qualifiedName;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_localizedText;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_localizedText;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_extensionObject;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_extensionObject;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_variant;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_variant;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_dataValue;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_dataValue;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_diagnosticInfo;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_diagnosticInfo;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_baseNode;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_baseNode;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_variableNode;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_variableNode;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_variableTypeNode;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_variableTypeNode;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_objectNode;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_objectNode;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_objectTypeNode;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_objectTypeNode;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_referenceTypeNode;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_referenceTypeNode;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_reference;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_reference;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_dataTypeNode;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_dataTypeNode;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_viewNode;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_viewNode;

extern OV_CLASS_DEF OV_CLASS_DEF_opcua_testObject;
OV_VAREXTERN OV_INSTPTR_ov_class pclass_opcua_testObject;

extern OV_ASSOCIATION_DEF OV_ASSOCIATION_DEF_opcua_networkLayerToConnection;
OV_VAREXTERN OV_INSTPTR_ov_association passoc_opcua_networkLayerToConnection;

extern OV_LIBRARY_DEF OV_LIBRARY_DEF_opcua;

OV_RESULT ov_library_setglobalvars_opcua(void);

OV_DLLFNCEXPORT OV_LIBRARY_DEF *ov_library_open_opcua(void);

#undef OV_VAREXTERN
#undef OV_FNCEXTERN

#ifdef __cplusplus
}
#endif

#endif

/*
*   End of file
*/
