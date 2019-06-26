/*
    DataTypeClass: RelativePath

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_RelativePath_h__
#define __OpcUaStackCore_RelativePath_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/RelativePathElement.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT RelativePath
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<RelativePath> SPtr;
        typedef std::vector<RelativePath::SPtr> Vec;
    
        RelativePath(void);
        RelativePath(const RelativePath& value);
        virtual ~RelativePath(void);
        
        RelativePathElementArray& elements(void);
        
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
        
        void copyTo(RelativePath& value);
        bool operator==(const RelativePath& value);
        bool operator!=(const RelativePath& value);
        RelativePath& operator=(const RelativePath& value);
    
      private:
        RelativePathElementArray elements_; //!< A list of elements in the path.
    
    };
    
    class DLLEXPORT RelativePathArray
    : public OpcUaArray<RelativePath::SPtr, SPtrTypeCoder<RelativePath> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<RelativePathArray> SPtr;
    };

}

#endif
