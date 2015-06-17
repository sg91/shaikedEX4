/*
 * security.h
 *
 *  Created on: Jun 10, 2015
 *      Author: Shaked
 */

#ifndef SECURITY_H_
#define SECURITY_H_
#include <string.h>
using namespace std;

namespace mtm{

	 enum QuarterType{
		FIRST_QUARTER,
		SECOND_QUARTER,
		THIRD_QUARTER,
		FOURTH_QUARTER
	};


	class Security{
		string name;
		double value;
		int amount;
		double prediction[4];
	//shaked
		int comparison(const Security& other) const;
	//~shaked
	public:
	//shaked
		Security(); //overide deafult constructor return not enough arguments or somthing
		Security(string name,double value, int amount=1);
		Security(const Security&); // copy constructor
		~Security(); // destructor

		// uses copy and destruct for assignment
		Security& operator=(const Security& other);
	// ~shaked

	//shai
		double GetValue() const
		{
			double returnValue = this->value;
			return returnValue;
		}

		void SetValue(double newValue)
		{
			this->value = newValue;
		}

		int GetAmount() const
		{
			int returnAmount = this->amount;
			return returnAmount;
		}

		void SetAmount(int newAmount)
		{
			this->amount = newAmount;
		}

		string GetName() const
		{
			string returnName = this->name;
			return returnName;

		}

		double getValue() const; //why do we have 2 of these?
		double calcRisk() const
		{
			int counter = 0;
			double sum = 0;

			for (int i = 0; i < 4; i++){
				if (this->prediction[i] != 0){
					counter++;
					sum += prediction[i];
				}
			}
			if (counter == 0){
				return 0;
			}
			double risk = ((sum - (counter*this->value))/counter);
			return risk;
		}

		//TODO this
		operator double(); // returns current total value maybe should add explicit
	//~shai

	//shaked
		double& operator[](QuarterType quarter);
	//~shaked

	//shai
		//TODO this
		// remember to check that securities added have the same name
		Security& operator+=(const Security& security);
		Security& operator+=(const int& amount);
		Security& operator-=(const Security& security);
		Security& operator-=(const int& amount);
		Security& operator*=(const Security& security);
		Security& operator*=(const int& amount);
	//~shai

	//shaked
		// ment to throw exception but im not sure it will cause code to not compile
		// better solution needed
		Security& operator/=(const Security& security);
		Security& operator/=(const int& amount);

		// nonmember function for symmetry
		//comparison (will utilize the private comparison function);
		friend bool operator<(const Security& security1,const Security& security2);
		friend bool operator<=(const Security& security1,const Security& security2);
		friend bool operator>(const Security& security1,const Security& security2);
		friend bool operator>=(const Security& security1,const Security& security2);
		friend bool operator==(const Security& security1,const Security& security2);
		friend bool operator!=(const Security& security1,const Security& security2);
	//~shaked


	};



}// end namespace mtm

#endif /* SECURITY_H_ */
