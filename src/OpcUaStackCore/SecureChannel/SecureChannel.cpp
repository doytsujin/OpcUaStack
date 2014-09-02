#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{

	SecureChannel::SecureChannel(IOService& ioService)
	: ioService_(&ioService) 
	, tcpConnection_(ioService.io_service())
	, partnerAddress_(boost::asio::ip::address::from_string("127.0.0.1"))
	, partnerPort_(4841)
	, channelDataBaseSPtr_(ChannelDataBase::construct())
	, channelId_(0)
	, debugMode_(false)
	{
	}

	SecureChannel::~SecureChannel(void)
	{
	}

	void 
	SecureChannel::debugMode(bool debugMode)
	{
		debugMode_ = debugMode;
	}

	ChannelDataBase::SPtr 
	SecureChannel::channelDataBase(void)
	{
		return channelDataBaseSPtr_;
	}

	TCPConnection& 
	SecureChannel::tcpConnection(void)
	{
		return tcpConnection_;
	}

	void 
	SecureChannel::asyncReadMessageHeader(void)
	{
		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannel::handleReadMessageHeader, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			8
		);
	}

	void 
	SecureChannel::handleReadMessageHeader(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		Log(Debug, "receive message header")
			.parameter("MessageHeaderLength", bytes_transfered);

		if (debugMode_) {
			std::iostream debug_ios(&is_);
			OpcUaStackCore::dumpHex(debug_ios);
		}

		if (error) {
			Log(Error, "receive message header error")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("ErrorCode", error.message());

			handleReadMessageHeaderError();
			return;
		}

		if (bytes_transfered == 0) {
			Log(Error, "connection is closed by partner")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_);

			handleReadMessageHeaderError();
			return;
		}

		// decode message header
		std::iostream is(&is_);
		MessageHeader messageHeader;
		messageHeader.opcUaBinaryDecode(is);

		switch(messageHeader.messageType())
		{
			case MessageType_Unknown:
			{
				handleReadMessageHeaderTypeUnknown(messageHeader);
				break;
			}
			case MessageType_Hello:
			{
				handleReadMessageHeaderTypeHello(messageHeader);
				break;
			}
			case MessageType_Acknowledge:
			{
				handleReadMessageHeaderTypeAcknowledge(messageHeader);
				break;
			}
			case MessageType_OpenSecureChannel:
			{
				handleReadMessageHeaderTypeOpenSecureChannel(messageHeader);
				break;
			}
			case MessageType_CloseSecureChannel:
			{
				handleReadMessageHeaderTypeCloseSecureChannel(messageHeader);
				break;
			}
			case MessageType_Error:
			{
				handleReadMessageHeaderTypeError(messageHeader);
				break;
			}
			case MessageType_Message:
			{
				handleReadMessageHeaderTypeMessage(messageHeader);
				break;
			}
		}
	}
		
	void 
	SecureChannel::handleReadMessageHeaderTypeUnknown(MessageHeader& messageHeader)
	{
		std::string messageTypeHexString;
		OpcUaStackCore::byteSequenceToHexString((uint8_t*)messageHeader.messageTypeString(), 3, messageTypeHexString);

		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", messageTypeHexString);
		handleReadMessageHeaderError();
	}
		
	void 
	SecureChannel::handleReadMessageHeaderTypeHello(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "Hello");
		handleReadMessageHeaderError();
	}
	
	void 
	SecureChannel::handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "Acknowledge");
		handleReadMessageHeaderError();
	}
	
	void 
	SecureChannel::handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "OpenSecureChannel");
		handleReadMessageHeaderError();
	}

	void 
	SecureChannel::handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "CloseSecureChannel");
		handleReadMessageHeaderError();
	}

	void 
	SecureChannel::handleReadMessageHeaderTypeError(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "Error");
		handleReadMessageHeaderError();
	}

	void 
	SecureChannel::handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "Message");
		handleReadMessageHeaderError();
	}

}