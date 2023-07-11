/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmoud <moulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:49:19 by moulmoud          #+#    #+#             */
/*   Updated: 2023/07/11 02:47:06 by moulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

class Car {
	private:
		std:: string model;
		int	yearModel;
	public:
		void setYearModel(int yearModel);
		void setModel(std:: string model);
		int getYearModel();
		std:: string getModel();
};

void Car:: setModel(std:: string model) {
	this->model = model;
}

int Car::getYearModel()
{
return (this->yearModel);
}

void Car:: setYearModel(int yearModel) {
	this->yearModel = yearModel;
}


std::string Car::getModel()
{
	return (this->model);
}




int main() {
	Car fiat;

	fiat.setModel("fiat");
	fiat.setYearModel(2014);
	std:: cout << fiat.getModel() << std:: endl;
	std:: cout << fiat.getYearModel() << std:: endl;
}
