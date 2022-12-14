// Generated by gencpp from file communication_interface/test2.msg
// DO NOT EDIT!


#ifndef COMMUNICATION_INTERFACE_MESSAGE_TEST2_H
#define COMMUNICATION_INTERFACE_MESSAGE_TEST2_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace communication_interface
{
template <class ContainerAllocator>
struct test2_
{
  typedef test2_<ContainerAllocator> Type;

  test2_()
    : data(0)  {
    }
  test2_(const ContainerAllocator& _alloc)
    : data(0)  {
  (void)_alloc;
    }



   typedef int32_t _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::communication_interface::test2_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::communication_interface::test2_<ContainerAllocator> const> ConstPtr;

}; // struct test2_

typedef ::communication_interface::test2_<std::allocator<void> > test2;

typedef boost::shared_ptr< ::communication_interface::test2 > test2Ptr;
typedef boost::shared_ptr< ::communication_interface::test2 const> test2ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::communication_interface::test2_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::communication_interface::test2_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::communication_interface::test2_<ContainerAllocator1> & lhs, const ::communication_interface::test2_<ContainerAllocator2> & rhs)
{
  return lhs.data == rhs.data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::communication_interface::test2_<ContainerAllocator1> & lhs, const ::communication_interface::test2_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace communication_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::communication_interface::test2_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::communication_interface::test2_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::communication_interface::test2_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::communication_interface::test2_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::communication_interface::test2_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::communication_interface::test2_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::communication_interface::test2_<ContainerAllocator> >
{
  static const char* value()
  {
    return "da5909fbe378aeaf85e547e830cc1bb7";
  }

  static const char* value(const ::communication_interface::test2_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xda5909fbe378aeafULL;
  static const uint64_t static_value2 = 0x85e547e830cc1bb7ULL;
};

template<class ContainerAllocator>
struct DataType< ::communication_interface::test2_<ContainerAllocator> >
{
  static const char* value()
  {
    return "communication_interface/test2";
  }

  static const char* value(const ::communication_interface::test2_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::communication_interface::test2_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 data\n"
;
  }

  static const char* value(const ::communication_interface::test2_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::communication_interface::test2_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct test2_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::communication_interface::test2_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::communication_interface::test2_<ContainerAllocator>& v)
  {
    s << indent << "data: ";
    Printer<int32_t>::stream(s, indent + "  ", v.data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COMMUNICATION_INTERFACE_MESSAGE_TEST2_H
