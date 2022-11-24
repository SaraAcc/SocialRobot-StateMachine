// Generated by gencpp from file qt_robot_interface/speech_configRequest.msg
// DO NOT EDIT!


#ifndef QT_ROBOT_INTERFACE_MESSAGE_SPEECH_CONFIGREQUEST_H
#define QT_ROBOT_INTERFACE_MESSAGE_SPEECH_CONFIGREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace qt_robot_interface
{
template <class ContainerAllocator>
struct speech_configRequest_
{
  typedef speech_configRequest_<ContainerAllocator> Type;

  speech_configRequest_()
    : language()
    , pitch(0)
    , speed(0)  {
    }
  speech_configRequest_(const ContainerAllocator& _alloc)
    : language(_alloc)
    , pitch(0)
    , speed(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _language_type;
  _language_type language;

   typedef int16_t _pitch_type;
  _pitch_type pitch;

   typedef int16_t _speed_type;
  _speed_type speed;





  typedef boost::shared_ptr< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> const> ConstPtr;

}; // struct speech_configRequest_

typedef ::qt_robot_interface::speech_configRequest_<std::allocator<void> > speech_configRequest;

typedef boost::shared_ptr< ::qt_robot_interface::speech_configRequest > speech_configRequestPtr;
typedef boost::shared_ptr< ::qt_robot_interface::speech_configRequest const> speech_configRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::qt_robot_interface::speech_configRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::qt_robot_interface::speech_configRequest_<ContainerAllocator1> & lhs, const ::qt_robot_interface::speech_configRequest_<ContainerAllocator2> & rhs)
{
  return lhs.language == rhs.language &&
    lhs.pitch == rhs.pitch &&
    lhs.speed == rhs.speed;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::qt_robot_interface::speech_configRequest_<ContainerAllocator1> & lhs, const ::qt_robot_interface::speech_configRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace qt_robot_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "08a23f216ce477ab09150cf3c5975177";
  }

  static const char* value(const ::qt_robot_interface::speech_configRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x08a23f216ce477abULL;
  static const uint64_t static_value2 = 0x09150cf3c5975177ULL;
};

template<class ContainerAllocator>
struct DataType< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "qt_robot_interface/speech_configRequest";
  }

  static const char* value(const ::qt_robot_interface::speech_configRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string language\n"
"int16  pitch\n"
"int16  speed\n"
;
  }

  static const char* value(const ::qt_robot_interface::speech_configRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.language);
      stream.next(m.pitch);
      stream.next(m.speed);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct speech_configRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::qt_robot_interface::speech_configRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::qt_robot_interface::speech_configRequest_<ContainerAllocator>& v)
  {
    s << indent << "language: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.language);
    s << indent << "pitch: ";
    Printer<int16_t>::stream(s, indent + "  ", v.pitch);
    s << indent << "speed: ";
    Printer<int16_t>::stream(s, indent + "  ", v.speed);
  }
};

} // namespace message_operations
} // namespace ros

#endif // QT_ROBOT_INTERFACE_MESSAGE_SPEECH_CONFIGREQUEST_H
