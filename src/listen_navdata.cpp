/* some code to just print everything received from the navdata topic */

#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <ardrone_autonomy/Navdata.h>

void navdata_callback( const ardrone_autonomy::Navdata &msg ) {
	int battery = msg.batteryPercent ;
	cout << "battery percent: " << battery << endl ;
}

int main( int argc, char *argv[] ) {
	ros::init( argc, argv, "cool_navdata_node" ) ;
	ros::NodeHandle nh ;
	ros::Subscriber navdata_sub ;

	navdata_sub = nh.subscribe("/ardrone/navdata", 1, navdata_callback ) ;
	ros::spin() ;

	return 0 ;	
}
