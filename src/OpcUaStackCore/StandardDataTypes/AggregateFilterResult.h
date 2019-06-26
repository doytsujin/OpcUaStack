/*
    DataTypeClass: AggregateFilterResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AggregateFilterResult_h__
#define __OpcUaStackCore_AggregateFilterResult_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/MonitoringFilterResult.h"
#include "OpcUaStackCore/StandardDataTypes/AggregateConfiguration.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AggregateFilterResult
    : public MonitoringFilterResult
    {
      public:
        typedef boost::shared_ptr<AggregateFilterResult> SPtr;
        typedef std::vector<AggregateFilterResult::SPtr> Vec;
    
        AggregateFilterResult(void);
        AggregateFilterResult(const AggregateFilterResult& value);
        virtual ~AggregateFilterResult(void);
        
        OpcUaUtcTime& revisedStartTime(void);
        OpcUaDuration& revisedProcessingInterval(void);
        AggregateConfiguration& revisedAggregateConfiguration(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual void opcUaBinaryEncode(std::ostream& os) const override;
        virtual void opcUaBinaryDecode(std::istream& is) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase) override;
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const override;
        virtual void out(std::ostream& os) override;
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const override;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt) override;
        
        void copyTo(AggregateFilterResult& value);
        bool operator==(const AggregateFilterResult& value);
        bool operator!=(const AggregateFilterResult& value);
        AggregateFilterResult& operator=(const AggregateFilterResult& value);
    
      private:
        OpcUaUtcTime revisedStartTime_;
        OpcUaDuration revisedProcessingInterval_;
        AggregateConfiguration revisedAggregateConfiguration_;
    
    };
    
    class DLLEXPORT AggregateFilterResultArray
    : public OpcUaArray<AggregateFilterResult::SPtr, SPtrTypeCoder<AggregateFilterResult> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<AggregateFilterResultArray> SPtr;
    };

}

#endif
