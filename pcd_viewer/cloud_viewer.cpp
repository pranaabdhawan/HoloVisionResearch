#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
    
int user_data;
    
int main (int argc, char* argv[])
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::visualization::PCLVisualizer viewer("PCD Cloud Viewer");

    for(int i = 1; i< argc; i++){
        std::string pcd_file = argv[i];
        pcl::io::loadPCDFile (pcd_file, *cloud);
        //blocks until the cloud is actually rendered
    }
    viewer.addPointCloud(cloud);
    
    //This will only get called once
    while(!viewer.wasStopped()) {
        viewer.spinOnce(100);
        boost::this_thread::sleep(boost::posix_time::microseconds(100000));
    }
    
    return 0;
}