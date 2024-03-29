// Generated by gencpp from file qt_vosk_app/speech_recognizeResponse.msg
// DO NOT EDIT!


#ifndef QT_VOSK_APP_MESSAGE_SPEECH_RECOGNIZERESPONSE_H
#define QT_VOSK_APP_MESSAGE_SPEECH_RECOGNIZERESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace qt_vosk_app
{
template <class ContainerAllocator>
struct speech_recognizeResponse_
{
  typedef speech_recognizeResponse_<ContainerAllocator> Type;

  speech_recognizeResponse_()
    : transcript()  {
    }
  speech_recognizeResponse_(const ContainerAllocator& _alloc)
    : transcript(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _transcript_type;
  _transcript_type transcript;





  typedef boost::shared_ptr< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> const> ConstPtr;

}; // struct speech_recognizeResponse_

typedef ::qt_vosk_app::speech_recognizeResponse_<std::allocator<void> > speech_recognizeResponse;

typedef boost::shared_ptr< ::qt_vosk_app::speech_recognizeResponse > speech_recognizeResponsePtr;
typedef boost::shared_ptr< ::qt_vosk_app::speech_recognizeResponse const> speech_recognizeResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator1> & lhs, const ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator2> & rhs)
{
  return lhs.transcript == rhs.transcript;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator1> & lhs, const ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace qt_vosk_app

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d57af9fafe11c5c53756ce2839af175d";
  }

  static const char* value(const ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd57af9fafe11c5c5ULL;
  static const uint64_t static_value2 = 0x3756ce2839af175dULL;
};

template<class ContainerAllocator>
struct DataType< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "qt_vosk_app/speech_recognizeResponse";
  }

  static const char* value(const ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string transcript\n"
"\n"
;
  }

  static const char* value(const ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.transcript);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct speech_recognizeResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::qt_vosk_app::speech_recognizeResponse_<ContainerAllocator>& v)
  {
    s << indent << "transcript: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.transcript);
  }
};

} // namespace message_operations
} // namespace ros

#endif // QT_VOSK_APP_MESSAGE_SPEECH_RECOGNIZERESPONSE_H
