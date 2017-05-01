/*
 * Camara.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef CAMARA_H_
#define CAMARA_H_

class Camara {
private:
	int x,y;
public:
	Camara(){x=0;y=0;};

	int get_x();
	void set_x(int nuevo_x);
	int get_y();
	void set_y(int nuevo_y);
};

#endif /* CAMARA_H_ */
