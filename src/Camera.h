#ifndef CAMERA_H_
#define CAMERA_H_

class Camera {
private:
	int x,y;
public:
	Camera(){x=0;y=0;};

	int get_x();
	void set_x(int new_x);
	int get_y();
	void set_y(int new_y);
};

#endif /* CAMERA_H_ */
