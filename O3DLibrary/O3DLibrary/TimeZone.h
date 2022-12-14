#pragma once
#include "O3DLibrary.h"
#include "Object.h"
#include "FString.h"
#include "DateTime.h"
#include <Windows.h>

namespace Core
{
	enum class ETimeZoneName
	{
		Afghanistan,
		Alaskan,
		Aleutian,
		Altai,
		Arab,
		Arabian,
		Arabic,
		Argentina,
		Astrakhan,
		Atlantic,
		AUS_Central,
		AUS_Central_W,
		AUS_Eastern,
		Azerbaijan,
		Azores,
		Bahia,
		Bangladesh,
		Belarus,
		Bougainville,
		Canada,
		Cape_Verde,
		Caucasus,
		Australia,
		America,
		Asia,
		Brazilian,
		Europe,
		European,
		Pacific,
		Central_Standard_Time,
		Central_Standard_Time_Mexico,
		Chatham_Islands,
		China,
		Cuba,
		Dateline,
		E_Africa,
		E_Australia,
		E_Europ,
		E_South_America,
		Easter_Island,
		Eastern_Standard,
		Easter_Standard_Mexico,
		Egypt,
		Ekaterinburg,
		Fiji,
		FLE_Standard,
		Georgian,
		GMT_Standard,
		Greenland,
		Greenwich,
		GTB,
		Haiti,
		Hawaiian,
		India,
		Iran,
		Israel,
		Jordan,
		Kaliningrad,
		Kamchatka,
		Korea,
		Libya,
		Line_Islands,
		Lord_Howe,
		Magadan,
		Magallanes,
		Marquesas,
		Mauritius,
		Mid_Atlantic,
		Middle_East,
		Montevideo,
		Morocoo,
		Mountain_Standard,
		Mountain_Standard_Mexico,
		Myanmar,
		N_Central_Asia,
		Namibia,
		Nepal,
		New_Zealand,
		NewFoundLand,
		Norfolk,
		North_Asia_East,
		North_Asia,
		North_Korea,
		Omsk,
		Pacific_Sa,
		Pacific_Standard,
		Pacific_Mexico,
		Pakistan,
		Paraguay,
		Qyzylorda,
		Romance,
		Russia_Time_Zone_10,
		Russia_Time_Zone_11,
		Russia_Time_Zone_3,
		Russian,
		SA_Eastern,
		SA_Pacific,
		SA_Western,
		SaintPierre,
		Sakhalin,
		Samoa,
		SaoTome,
		Saratov,
		SE_Asia,
		Singapore,
		SouthAfrica,
		SouthSudan,
		SriLanka,
		Sudan,
		Syria,
		Taipei,
		Tasmania,
		Tocantins,
		Tokyo,
		Tomsk,
		Tonga,
		Transbaikal,
		Turkey,
		Turks,
		Ulaanbaatar,
		US_Eastern,
		US_Mountain,
		UTC,
		UTC12,
		UTC13,
		UTC02,
		UTC08,
		UTC09,
		UTC11,
		Venezuela,
		Vladivostok,
		Volgograd,
		W_Australia,
		W_CentralAfrica,
		W_Europ,
		W_Mongolia,
		West_Asia,
		West_Bank,
		West_Pacific,
		Yakutsk,
		Yukon
	};

	class O3DLIBRARY_API TimeZone : public Object
	{
#pragma region f/p
	private:
		ETimeZoneName timeZone = ETimeZoneName::America;
		DWORD result = DWORD();
		DateTime time = DateTime(0, 0, 0);
		PrimitiveType::FString timeZoneName = "";
#pragma endregion
#pragma region constructor
	public:
		TimeZone() = default;
		TimeZone(const ETimeZoneName& _timeZone);
		TimeZone(const TimeZone& _copy);
#pragma endregion
#pragma region methods
	private:
		void Init();
	public:
		class DateTime Time() const;
#pragma endregion
#pragma region override
	public:
		PrimitiveType::FString ToString() const;
#pragma endregion

	};
}
