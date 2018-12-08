/*
    DataTypeClass: ModificationInfo

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ModificationInfo_h__
#define __OpcUaStackCore_ModificationInfo_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryUpdateType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ModificationInfo
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ModificationInfo> SPtr;
        typedef std::vector<ModificationInfo::SPtr> Vec;
    
        ModificationInfo(void);
        virtual ~ModificationInfo(void);
        
        OpcUaUtcTime& modificationTime(void);
        HistoryUpdateType& updateType(void);
        OpcUaString& userName(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual std::string namespaceName(void);
        virtual std::string typeName(void);
        virtual OpcUaNodeId typeId(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual OpcUaNodeId jsonTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
        virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonEncode(boost::property_tree::ptree& pt);
        virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonDecode(boost::property_tree::ptree& pt);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(ModificationInfo& value);
        bool operator==(const ModificationInfo& value);
        bool operator!=(const ModificationInfo& value);
        ModificationInfo& operator=(const ModificationInfo& value);
    
      private:
        OpcUaUtcTime modificationTime_;
        HistoryUpdateType updateType_;
        OpcUaString userName_;
    
    };
    
    class ModificationInfoArray
    : public OpcUaArray<ModificationInfo::SPtr, SPtrTypeCoder<ModificationInfo> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ModificationInfoArray> SPtr;
    };

}

#endif
