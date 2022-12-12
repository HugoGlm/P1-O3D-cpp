#pragma once
#include "Client/Client.h"
#include "../Utils/DateTime/DateTime.h"

class Booking :  public Object
{
	DECLARE_CLASS_INFO(Object)
#pragma region f/p
private:
	DateTime arrivedDate = DateTime();
	DateTime departureDate = DateTime();
	Client client = Client();
	int numberOfPeople = 1;
#pragma endregion
#pragma region constructor
public:
	Booking() = default;
	Booking(const DateTime& _arrivedDate, const DateTime& _departureDate, const Client& _client, int _numberOfPeople);
	Booking(const Booking& _copy);
#pragma endregion
#pragma region methods
	DateTime ArrivedDate() const;
	DateTime DepartureDate() const;
	Client GetCllient() const;
	int NumberOfPeople() const;
#pragma endregion

};

