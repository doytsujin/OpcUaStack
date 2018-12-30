/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_RegisterForwardMethod_h__
#define __OpcUaStackServer_RegisterForwardMethod_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardMethod
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardMethod> SPtr;

		RegisterForwardMethod(void);
		virtual ~RegisterForwardMethod(void);

		void setMethodCallback(Callback& callback);
		template<typename T>
		  void setMethodCallback(T handler) {
			  Callback callback;
			  callback.reset(handler);
			  setMethodCallback(callback);
		  }

		bool query(ApplicationServiceIf* applicationServiceIf);
		OpcUaStatusCode resultCode(void);

	  private:
		std::vector<OpcUaNodeId> nodes_;
		ForwardNodeSync forwardNodeSync_;
		OpcUaStatusCode resultCode_;
	};

}
#endif
