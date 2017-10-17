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

#ifndef __OpcUaStackPubSub_UDPClient_h__
#define __OpcUaStackPubSub_UDPClient_h__

#include <iostream>
#include <boost/asio.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Utility/IOThread.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT UDPClient
	{
	  public:
		UDPClient(void);
		~UDPClient(void);

		void ioThread(IOThread::SPtr& ioThread);
		bool open(void);
		bool close(void);

		template<typename BUFFER>
		  void sendTo(
		      BUFFER& buffer,
			  boost::asio::ip::udp::endpoint& endpoint
		  )
		  {
			  socket_->send_to(buffer, endpoint);
		  }

		template<typename BUFFER>
		  void sendTo(
		      BUFFER& buffer1,
			  BUFFER& buffer2,
			  boost::asio::ip::udp::endpoint& endpoint
		  )
		  {
			  std::vector<boost::asio::const_buffer> buffer;
			  buffer.push_back(boost::asio::buffer(buffer1.data()));
			  buffer.push_back(boost::asio::buffer(buffer2.data()));
			  socket_->send_to(buffer, endpoint);
		  }

		template<typename BUFFER>
		  void sendTo(
		      BUFFER& buffer1,
			  BUFFER& buffer2,
			  BUFFER& buffer3,
			  boost::asio::ip::udp::endpoint& endpoint
		  )
		  {
			  std::vector<boost::asio::const_buffer> buffer;
			  buffer.push_back(boost::asio::buffer(buffer1.data()));
			  buffer.push_back(boost::asio::buffer(buffer2.data()));
			  buffer.push_back(boost::asio::buffer(buffer3.data()));
			  socket_->send_to(buffer, endpoint);
		  }

		template<typename HANDLER>
		  void sendTo(
		      std::vector<boost::asio::const_buffer>& buffer,
			  boost::asio::ip::udp::endpoint& endpoint
		  )
		  {
			  socket_->send_to(buffer, endpoint);
		  }

		template<typename BUFFER, typename HANDLER>
		  void asyncReceive(BUFFER& buffer, HANDLER handler)
		  {
			  socket_->async_receive(
				  buffer,
				  handler
			  );
		  }

	  private:
		IOThread::SPtr ioThread_;
		boost::asio::ip::udp::socket* socket_;
	};

}

#endif
