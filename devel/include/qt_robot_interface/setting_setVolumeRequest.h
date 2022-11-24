// Generated by gencpp from file qt_robot_interface/setting_setVolumeRequest.msg
// DO NOT EDIT!


#ifndef QT_ROBOT_INTERFACE_MESSAGE_SETTING_SETVOLUMEREQUEST_H
#define QT_ROBOT_INTERFACE_MESSAGE_SETTING_SETVOLUMEREQUEST_H


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
struct setting_setVolumeRequest_
{
  typedef setting_setVolumeRequest_<ContainerAllocator> Type;

  setting_setVolumeRequest_()
    : volume(0)  {
    }
  setting_setVolumeRequest_(const ContainerAllocator& _alloc)
    : volume(0)  {
  (void)_alloc;
    }



   typedef uint8_t _volume_type;
  _volume_type volume;





  typedef boost::shared_ptr< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> const> ConstPtr;

}; // struct setting_setVolumeRequest_

typedef ::qt_robot_interface::setting_setVolumeRequest_<std::allocator<void> > setting_setVolumeRequest;

typedef boost::shared_ptr< ::qt_robot_interface::setting_setVolumeRequest > setting_setVolumeRequestPtr;
typedef boost::shared_ptr< ::qt_robot_interface::setting_setVolumeRequest const> setting_setVolumeRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator1> & lhs, const ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator2> & rhs)
{
  return lhs.volume == rhs.volume;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator1> & lhs, const ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace qt_robot_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0a86acf73473ef36a9dea539b67321f7";
  }

  static const char* value(const ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0a86acf73473ef36ULL;
  static const uint64_t static_value2 = 0xa9dea539b67321f7ULL;
};

template<class ContainerAllocator>
struct DataType< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "qt_robot_interface/setting_setVolumeRequest";
  }

  static const char* value(const ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 volume\n"
;
  }

  static const char* value(const ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.volume);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct setting_setVolumeRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::qt_robot_interface::setting_setVolumeRequest_<ContainerAllocator>& v)
  {
    s << indent << "volume: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.volume);
  }
};

} // namespace message_operations
} // namespace ros

#endif // QT_ROBOT_INTERFACE_MESSAGE_SETTING_SETVOLUMEREQUEST_H