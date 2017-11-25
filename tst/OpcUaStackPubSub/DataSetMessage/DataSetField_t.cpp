#include "unittest.h"

#include <boost/asio.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetField.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;

BOOST_AUTO_TEST_SUITE(DataSetField_)

BOOST_AUTO_TEST_CASE(DataSetField_)
{
	std::cout << "DataSetField_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataSetField_encode_decode_variant)
{
	DataSetField value1, value2;
	OpcUaVariant::SPtr variant1, variant2;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	variant1 = constructSPtr<OpcUaVariant>();
	variant1->setValue(OpcUaNodeId(4711));
	value1.variant(variant1);

	value1.opcUaBinaryEncode(ios);

	value2.createObject(VariantEncoding);
	value2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(value2.dataType() == VariantEncoding);
	variant2 = value2.variant();
	OpcUaNodeId nodeId;
	variant2->getValue(nodeId);
	BOOST_REQUIRE(nodeId == OpcUaNodeId(4711));
}

BOOST_AUTO_TEST_CASE(DataSetField_encode_decode_dataValue)
{
	DataSetField value1, value2;
	OpcUaDataValue::SPtr dataValue1, dataValue2;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	dataValue1 = constructSPtr<OpcUaDataValue>();
	dataValue1->statusCode(BadOutOfMemory);
	dataValue1->variant()->setValue(OpcUaNodeId(4711));

	value1.dataValue(dataValue1);
	value1.opcUaBinaryEncode(ios);

	value2.createObject(DataValueEncoding);
	value2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(value2.dataType() == DataValueEncoding);
	dataValue2  = value2.dataValue();
	OpcUaNodeId nodeId;
	dataValue2->variant()->getValue(nodeId);
	BOOST_REQUIRE(nodeId == OpcUaNodeId(4711));
	BOOST_REQUIRE(dataValue2->statusCode() == BadOutOfMemory);
}

BOOST_AUTO_TEST_SUITE_END()
