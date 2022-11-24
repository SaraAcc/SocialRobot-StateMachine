// Generated by gencpp from file qt_nuitrack_app/HandInfo.msg
// DO NOT EDIT!


#ifndef QT_NUITRACK_APP_MESSAGE_HANDINFO_H
#define QT_NUITRACK_APP_MESSAGE_HANDINFO_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace qt_nuitrack_app
{
template <class ContainerAllocator>
struct HandInfo_
{
  typedef HandInfo_<ContainerAllocator> Type;

  HandInfo_()
    : id(0)
    , right_projection()
    , right_real()
    , right_click(false)
    , right_pressure(0)
    , left_projection()
    , left_real()
    , left_click(false)
    , left_pressure(0)  {
    }
  HandInfo_(const ContainerAllocator& _alloc)
    : id(0)
    , right_projection(_alloc)
    , right_real(_alloc)
    , right_click(false)
    , right_pressure(0)
    , left_projection(_alloc)
    , left_real(_alloc)
    , left_click(false)
    , left_pressure(0)  {
  (void)_alloc;
    }



   typedef int32_t _id_type;
  _id_type id;

   typedef std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> _right_projection_type;
  _right_projection_type right_projection;

   typedef std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> _right_real_type;
  _right_real_type right_real;

   typedef uint8_t _right_click_type;
  _right_click_type right_click;

   typedef int32_t _right_pressure_type;
  _right_pressure_type right_pressure;

   typedef std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> _left_projection_type;
  _left_projection_type left_projection;

   typedef std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> _left_real_type;
  _left_real_type left_real;

   typedef uint8_t _left_click_type;
  _left_click_type left_click;

   typedef int32_t _left_pressure_type;
  _left_pressure_type left_pressure;





  typedef boost::shared_ptr< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> const> ConstPtr;

}; // struct HandInfo_

typedef ::qt_nuitrack_app::HandInfo_<std::allocator<void> > HandInfo;

typedef boost::shared_ptr< ::qt_nuitrack_app::HandInfo > HandInfoPtr;
typedef boost::shared_ptr< ::qt_nuitrack_app::HandInfo const> HandInfoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::qt_nuitrack_app::HandInfo_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::qt_nuitrack_app::HandInfo_<ContainerAllocator1> & lhs, const ::qt_nuitrack_app::HandInfo_<ContainerAllocator2> & rhs)
{
  return lhs.id == rhs.id &&
    lhs.right_projection == rhs.right_projection &&
    lhs.right_real == rhs.right_real &&
    lhs.right_click == rhs.right_click &&
    lhs.right_pressure == rhs.right_pressure &&
    lhs.left_projection == rhs.left_projection &&
    lhs.left_real == rhs.left_real &&
    lhs.left_click == rhs.left_click &&
    lhs.left_pressure == rhs.left_pressure;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::qt_nuitrack_app::HandInfo_<ContainerAllocator1> & lhs, const ::qt_nuitrack_app::HandInfo_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace qt_nuitrack_app

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ebda9d77d8f24f2a507d651777ac1949";
  }

  static const char* value(const ::qt_nuitrack_app::HandInfo_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xebda9d77d8f24f2aULL;
  static const uint64_t static_value2 = 0x507d651777ac1949ULL;
};

template<class ContainerAllocator>
struct DataType< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "qt_nuitrack_app/HandInfo";
  }

  static const char* value(const ::qt_nuitrack_app::HandInfo_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#std_msgs/Header header\n"
"int32 id\n"
"#The normalized projective (x, y) coordinate of the right hand\n"
"float32[] right_projection\n"
"#The (x,y,z) coordinate of the right hand in the world system.\n"
"float32[] right_real\n"
"bool right_click\n"
"int32 right_pressure\n"
"#The normalized projective (x, y) coordinate of the left hand\n"
"float32[] left_projection\n"
"#The (x,y,z) coordinate of the left hand in the world system.\n"
"float32[] left_real\n"
"bool left_click\n"
"int32 left_pressure\n"
;
  }

  static const char* value(const ::qt_nuitrack_app::HandInfo_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.right_projection);
      stream.next(m.right_real);
      stream.next(m.right_click);
      stream.next(m.right_pressure);
      stream.next(m.left_projection);
      stream.next(m.left_real);
      stream.next(m.left_click);
      stream.next(m.left_pressure);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct HandInfo_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::qt_nuitrack_app::HandInfo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::qt_nuitrack_app::HandInfo_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.id);
    s << indent << "right_projection[]" << std::endl;
    for (size_t i = 0; i < v.right_projection.size(); ++i)
    {
      s << indent << "  right_projection[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.right_projection[i]);
    }
    s << indent << "right_real[]" << std::endl;
    for (size_t i = 0; i < v.right_real.size(); ++i)
    {
      s << indent << "  right_real[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.right_real[i]);
    }
    s << indent << "right_click: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.right_click);
    s << indent << "right_pressure: ";
    Printer<int32_t>::stream(s, indent + "  ", v.right_pressure);
    s << indent << "left_projection[]" << std::endl;
    for (size_t i = 0; i < v.left_projection.size(); ++i)
    {
      s << indent << "  left_projection[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.left_projection[i]);
    }
    s << indent << "left_real[]" << std::endl;
    for (size_t i = 0; i < v.left_real.size(); ++i)
    {
      s << indent << "  left_real[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.left_real[i]);
    }
    s << indent << "left_click: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.left_click);
    s << indent << "left_pressure: ";
    Printer<int32_t>::stream(s, indent + "  ", v.left_pressure);
  }
};

} // namespace message_operations
} // namespace ros

#endif // QT_NUITRACK_APP_MESSAGE_HANDINFO_H
