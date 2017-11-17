/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackPubSub/DataSetMessage/DataKeyFrameDataSetMessage.h"

namespace OpcUaStackPubSub
{

	DataKeyFrameDataSetMessage::DataKeyFrameDataSetMessage(void)
	: dataSetFields_(constructSPtr<DataSetFieldArray>())
	, fieldEncoding_(VariantEncoding)
	{
		messageType(DataKeyFrame);
	}

	DataKeyFrameDataSetMessage::~DataKeyFrameDataSetMessage(void)
	{
	}

	DataSetFieldArray::SPtr&
	DataKeyFrameDataSetMessage::dataSetFields(void)
	{
		return dataSetFields_;
	}

	void
	DataKeyFrameDataSetMessage::fieldEncoding(FieldEncoding fieldEncoding)
	{
		fieldEncoding_ = fieldEncoding;
	}

	void
	DataKeyFrameDataSetMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		uint16_t fieldCount = dataSetFields_->size();
		if (fieldCount == 0) return;

		OpcUaNumber::opcUaBinaryEncode(os, fieldCount);
		for (uint32_t idx=0; idx<fieldCount; idx++) {
			DataSetField::SPtr dataSetField;
			dataSetFields_->get(idx, dataSetField);

			dataSetField->opcUaBinaryEncode(os);
		}
	}

	void
	DataKeyFrameDataSetMessage::opcUaBinaryDecode(std::istream& is)
	{
		uint16_t fieldCount;
		OpcUaNumber::opcUaBinaryDecode(is, fieldCount);
		if (fieldCount == 0) return;

		dataSetFields_->resize(fieldCount);
		for (uint32_t idx=0; idx<fieldCount; idx++) {
			DataSetField::SPtr dataSetField = constructSPtr<DataSetField>();

			if (fieldEncoding_ == VariantEncoding) dataSetField->createObject(DataSetField::DT_Variant);
			else if (fieldEncoding_ == DataValueEncoding) dataSetField->createObject(DataSetField::DT_DataValue);
			else dataSetField->createObject(DataSetField::DT_MetaDataValue);

			dataSetField->opcUaBinaryDecode(is);
			dataSetFields_->push_back(dataSetField);
		}
	}

}
