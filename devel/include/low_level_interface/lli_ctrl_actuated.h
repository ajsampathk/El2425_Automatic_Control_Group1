// Generated by gencpp from file low_level_interface/lli_ctrl_actuated.msg
// DO NOT EDIT!


#ifndef LOW_LEVEL_INTERFACE_MESSAGE_LLI_CTRL_ACTUATED_H
#define LOW_LEVEL_INTERFACE_MESSAGE_LLI_CTRL_ACTUATED_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace low_level_interface
{
template <class ContainerAllocator>
struct lli_ctrl_actuated_
{
  typedef lli_ctrl_actuated_<ContainerAllocator> Type;

  lli_ctrl_actuated_()
    : steering(0)
    , velocity(0)
    , transmission(0)
    , differential_front(0)
    , differential_rear(0)
    , ctrl_code(0)
    , voltage(0)
    , current(0)
    , energy_consumed(0)  {
    }
  lli_ctrl_actuated_(const ContainerAllocator& _alloc)
    : steering(0)
    , velocity(0)
    , transmission(0)
    , differential_front(0)
    , differential_rear(0)
    , ctrl_code(0)
    , voltage(0)
    , current(0)
    , energy_consumed(0)  {
  (void)_alloc;
    }



   typedef int8_t _steering_type;
  _steering_type steering;

   typedef int8_t _velocity_type;
  _velocity_type velocity;

   typedef int8_t _transmission_type;
  _transmission_type transmission;

   typedef int8_t _differential_front_type;
  _differential_front_type differential_front;

   typedef int8_t _differential_rear_type;
  _differential_rear_type differential_rear;

   typedef int8_t _ctrl_code_type;
  _ctrl_code_type ctrl_code;

   typedef int8_t _voltage_type;
  _voltage_type voltage;

   typedef int8_t _current_type;
  _current_type current;

   typedef int8_t _energy_consumed_type;
  _energy_consumed_type energy_consumed;





  typedef boost::shared_ptr< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> const> ConstPtr;

}; // struct lli_ctrl_actuated_

typedef ::low_level_interface::lli_ctrl_actuated_<std::allocator<void> > lli_ctrl_actuated;

typedef boost::shared_ptr< ::low_level_interface::lli_ctrl_actuated > lli_ctrl_actuatedPtr;
typedef boost::shared_ptr< ::low_level_interface::lli_ctrl_actuated const> lli_ctrl_actuatedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace low_level_interface

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'low_level_interface': ['/home/nvidia/catkin_ws/src/low_level_interface/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6c801b9e27d9831fee1704e6d7985df4";
  }

  static const char* value(const ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6c801b9e27d9831fULL;
  static const uint64_t static_value2 = 0xee1704e6d7985df4ULL;
};

template<class ContainerAllocator>
struct DataType< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> >
{
  static const char* value()
  {
    return "low_level_interface/lli_ctrl_actuated";
  }

  static const char* value(const ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 steering \n\
int8 velocity\n\
int8 transmission\n\
int8 differential_front\n\
int8 differential_rear\n\
int8 ctrl_code\n\
int8 voltage\n\
int8 current\n\
int8 energy_consumed\n\
";
  }

  static const char* value(const ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.steering);
      stream.next(m.velocity);
      stream.next(m.transmission);
      stream.next(m.differential_front);
      stream.next(m.differential_rear);
      stream.next(m.ctrl_code);
      stream.next(m.voltage);
      stream.next(m.current);
      stream.next(m.energy_consumed);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct lli_ctrl_actuated_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::low_level_interface::lli_ctrl_actuated_<ContainerAllocator>& v)
  {
    s << indent << "steering: ";
    Printer<int8_t>::stream(s, indent + "  ", v.steering);
    s << indent << "velocity: ";
    Printer<int8_t>::stream(s, indent + "  ", v.velocity);
    s << indent << "transmission: ";
    Printer<int8_t>::stream(s, indent + "  ", v.transmission);
    s << indent << "differential_front: ";
    Printer<int8_t>::stream(s, indent + "  ", v.differential_front);
    s << indent << "differential_rear: ";
    Printer<int8_t>::stream(s, indent + "  ", v.differential_rear);
    s << indent << "ctrl_code: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ctrl_code);
    s << indent << "voltage: ";
    Printer<int8_t>::stream(s, indent + "  ", v.voltage);
    s << indent << "current: ";
    Printer<int8_t>::stream(s, indent + "  ", v.current);
    s << indent << "energy_consumed: ";
    Printer<int8_t>::stream(s, indent + "  ", v.energy_consumed);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LOW_LEVEL_INTERFACE_MESSAGE_LLI_CTRL_ACTUATED_H
