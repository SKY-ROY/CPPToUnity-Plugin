#include "opencv2/opencv.hpp"

struct Color32
{
	uchar red;
	uchar green;
	uchar blue;
	uchar alpha;
};

extern "C" 
{	
	int ComputerVision(int num)
	{
		return num + 0;
	}
	int ProcessImage(Color32** rawImage, int width, int height, int operationCount)
	{
		using namespace cv;

		// create an opencv object sharing the same data space
		Mat image(height, width, CV_8UC4, *rawImage);

		// start with flip (in both directions) if your image looks inverted
		flip(image, image, -1);

		// start processing the image
		// ************************************************

		Mat edges;
		Canny(image, edges, 50, 200);
		dilate(edges, edges, (5, 5));
		cvtColor(edges, edges, COLOR_GRAY2RGBA);
		normalize(edges, edges, 0, 1, NORM_MINMAX);
		multiply(image, edges, image);

		// end processing the image
		// ************************************************

		// flip again (just vertically) to get the right orientation
		flip(image, image, 0);

		//Put image-processing algo here 
		return ++operationCount;
	}
}
