// Generated by gencpp from file qt_gesture_controller/gesture_recordRequest.msg
// DO NOT EDIT!


#ifndef QT_GESTURE_CONTROLLER_MESSAGE_GESTURE_RECORDREQUEST_H
#define QT_GESTURE_CONTROLLER_MESSAGE_GESTURE_RECORDREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace qt_gesture_controller
{
template <class ContainerAllocator>
struct gesture_recordRequest_
{
  typedef gesture_recordRequest_<ContainerAllocator> Type;

  gesture_recordRequest_()
    : parts()
    , idleParts(false)
    , wait(0)
    , timeout(0)  {
    }
  gesture_recordRequest_(const ContainerAllocator& _alloc)
    : parts(_alloc)
    , idleParts(false)
    , wait(0)
    , timeout(0)  {
  (void)_alloc;
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> _parts_type;
  _parts_type parts;

   typedef uint8_t _idleParts_type;
  _idleParts_type idleParts;

   typedef uint8_t _wait_type;
  _wait_type wait;

   typedef uint8_t _timeout_type;
  _timeout_type timeout;





  typedef boost::shared_ptr< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> const> ConstPtr;

}; // struct gesture_recordRequest_

typedef ::qt_gesture_controller::gesture_recordRequest_<std::allocator<void> > gesture_recordRequest;

typedef boost::shared_ptr< ::qt_gesture_controller::gesture_recordRequest > gesture_recordRequestPtr;
typedef boost::shared_ptr< ::qt_gesture_controller::gesture_recordRequest const> gesture_recordRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator1> & lhs, const ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator2> & rhs)
{
  return lhs.parts == rhs.parts &&
    lhs.idleParts == rhs.idleParts &&
    lhs.wait == rhs.wait &&
    lhs.timeout == rhs.timeout;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator1> & lhs, const ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace qt_gesture_controller

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7b28f524f349bbb7a5f69f2378308888";
  }

  static const char* value(const ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7b28f524f349bbb7ULL;
  static const uint64_t static_value2 = 0xa5f69f2378308888ULL;
};

template<class ContainerAllocator>
struct DataType< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "qt_gesture_controller/gesture_recordRequest";
  }

  static const char* value(const ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# an array of robot parts (e.g. ['left_arm', 'right_arm'])\n"
"string[] parts\n"
"\n"
"# make parts idle\n"
"bool idleParts\n"
"\n"
"# wait for desired seconds before starting record\n"
"uint8 wait\n"
"\n"
"# max recording time in second\n"
"uint8 timeout\n"
"\n"
;
  }

  static const char* value(const ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.parts);
      stream.next(m.idleParts);
      stream.next(m.wait);
      stream.next(m.timeout);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct gesture_recordRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::qt_gesture_controller::gesture_recordRequest_<ContainerAllocator>& v)
  {
    s << indent << "parts[]" << std::endl;
    for (size_t i = 0; i < v.parts.size(); ++i)
    {
      s << indent << "  parts[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.parts[i]);
    }
    s << indent << "idleParts: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.idleParts);
    s << indent << "wait: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wait);
    s << indent << "timeout: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.timeout);
  }
};

} // namespace message_operations
} // namespace ros

#endif // QT_GESTURE_CONTROLLER_MESSAGE_GESTURE_RECORDREQUEST_H