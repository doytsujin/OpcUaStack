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

   Autor: Aleksey Timin (timin-ayu@nefteavtomatika.ru)
 */

#include "OpcUaStackServer/Filter/EqualsFilterNode.h"

namespace OpcUaStackServer
{
    EqualsFilterNode::EqualsFilterNode(const std::vector<FilterNode::SPtr>& args)
    {
        arg1_ = args[0];
        arg2_ = args[1];
    }

    EqualsFilterNode::~EqualsFilterNode()
    {

    }

    bool
	EqualsFilterNode::evaluate(OpcUaVariant& value)
    {
        //FIXME: Need conversions;

        OpcUaVariant v1;
        if (!arg1_->evaluate(v1)) {
        	return false;
        }
        OpcUaVariant v2;
        if (!arg2_->evaluate(v2)) {
        	return false;
        }

        value.set<OpcUaBoolean>(v1 == v2);
        return true;
    }
}
