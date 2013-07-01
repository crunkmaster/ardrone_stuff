/* some code to just print everything received from the navdata topic */

#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback( const std_msgs::String::ConstPtr &msg ) {
	ROS_INFO("[%s]", msg -> data.c_str() ) ;
}

int main( int argc, char *argv[] ) {
	
	ros::init( argc, argv, "cool_navdata_node" ) ;
	ros::NodeHandle nh ;
	ros::Subscriber navdata_sub = nh.subscribe("ardrone/navdata", 1000, chatterCallback ) ;
	ros::spin() ;

	return 0 ;	
}
