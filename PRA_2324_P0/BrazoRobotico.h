#include <iostream>


class BrazoRobotico {

	private:

		float coorX;
		float coorY;
		float coorZ;
		bool obj;

	public:
		BrazoRobotico(double x, double y, double z);
		bool coger();
		bool soltar();
		void mover(double x, double y, double z);

};
