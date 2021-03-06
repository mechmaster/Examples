#include <vpgl/algo/vpgl_triangulate_points.h>

static const vgl_point_3d<double> GOAL(1.0, 1.0, 1.0);
static const double TOL = .001;

// Creates a perspective camera looking at pt, and adds the camera and
// the projection of GOAL to the list.
static void add_pt_and_cam(
    vgl_homg_point_3d<double> pt,
    vgl_vector_3d<double> trans,
    vcl_vector<vgl_point_2d<double> > &points,
    vcl_vector<vpgl_perspective_camera<double> > &cameras)
{
    vpgl_perspective_camera<double> cam;
    cam.look_at(pt);
    cam.set_translation(trans);

    cameras.push_back(cam);

    double x,y;
    cam.project(GOAL.x(), GOAL.y(), GOAL.z(), x, y);
    
    std::cout << "x: " << x << " y: " << y << std::endl;

    points.push_back(vgl_point_2d<double>(x, y));
}

// Adds a bunch of cameras and points to the lists using the above method.
static void get_cams_and_pts(
    vcl_vector<vgl_point_2d<double> > &points,
    vcl_vector<vpgl_perspective_camera<double> > &cameras){

    add_pt_and_cam(
        vgl_homg_point_3d<double>(0.0, 1.0, 1.0),
        vgl_vector_3d<double>(-1.0, 1.0, 1.0),
        points, cameras);

    add_pt_and_cam(
        vgl_homg_point_3d<double>(1.0, 0.0, 1.0),
        vgl_vector_3d<double>(1.0, -1.0, 1.0),
        points, cameras);

    add_pt_and_cam(
        vgl_homg_point_3d<double>(1.0, 1.0, 0.0),
        vgl_vector_3d<double>(1.0, 1.0, -1.0),
        points, cameras);

    add_pt_and_cam(
        vgl_homg_point_3d<double>(1.0, 1.0, 1.0),
        vgl_vector_3d<double>(0.0, 0.0, 0.0),
        points, cameras);
}

int main()
{
  // First, get the cameras and points we'll be using to triangulate
  vcl_vector<vgl_point_2d<double> > points;
  vcl_vector<vpgl_perspective_camera<double> > cameras;
  get_cams_and_pts(points, cameras);

  // Perform the triangulation
  vgl_point_3d<double> pt;
  double err = vpgl_triangulate_points::triangulate(points, cameras, pt);

  vcl_cout << "Error is " << err << "." << vcl_endl;

  // Test the result
  std::cout << "pt is: " << pt << std::endl
	    << " and should be " << GOAL << std::endl;
  return 0;
}
