# include <iostream>

class Rectangle{
	private:
		int width;
		int height;
	public:
		void setWidth(int width) { this->width = width;}
		void setHeight(int height) {this->height = height;}
		int getWidth() { return width;}
		int getHeight() { return height;}
		int getArea() { return (height * width);}
};

int main() {
	Rectangle rectangle;

	rectangle.setWidth(42);
	rectangle.setHeight(42);
	std:: cout << "Width:" << rectangle.getWidth() << std::endl;
	std:: cout << "Height:" << rectangle.getHeight() << std::endl;
	std:: cout << "rectangle Area:" << rectangle.getArea() << std::endl;
	return 0;
}
