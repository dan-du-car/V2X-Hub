/*
 * Units.h
 *
 *  Created on: Apr 17, 2017
 *      @author: gmb
 */

#ifndef INCLUDE_UNITS_H_
#define INCLUDE_UNITS_H_

#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#include <cmath>
#define __STRICT_ANSI__
#else
#include <cmath>
#endif

namespace tmx {
namespace messages {

#ifndef STATIC_CONSTEXPR
#if __cplusplus > 199711L
#define STATIC_CONSTEXPR static constexpr
#define INVERT_EXPR(X) 1.0 / X
#else
#define STATIC_CONSTEXPR static const
#define INVERT_EXPR(X) 1.0 / (CONST_ ## X)
#endif
#endif

// Constant macros are used to handle different compiler needs
// Fixed values
#define CONST_SEC_PER_MIN			60
#define CONST_MIN_PER_HR			60
#define CONST_HR_PER_DAY			24
#define CONST_INCHES_PER_METER		39.37007874
#define CONST_FEET_PER_MILE			5280.0
#define CONST_SQMETERS_PER_ACRE		4046.856
// Expression value
#define CONST_SEC_PER_HR			(CONST_SEC_PER_MIN * CONST_MIN_PER_HR)
#define CONST_SEC_PER_DAY			(CONST_SEC_PER_HR * CONST_HR_PER_DAY)
#define CONST_METERS_PER_FOOT		(12.0 / CONST_INCHES_PER_METER)
#define CONST_METERS_PER_MILE 	 	(CONST_METERS_PER_FOOT * CONST_FEET_PER_MILE)
#define CONST_KM_PER_MILE			(CONST_METERS_PER_MILE / 1000.0)
#define CONST_KPH_PER_MPH			(CONST_KM_PER_MILE)
#define CONST_MPS_PER_KPH			(1000.0 / CONST_SEC_PER_HR)
#define CONST_MPS_PER_MPH			(CONST_METERS_PER_MILE / CONST_SEC_PER_HR)
#define CONST_MPS_PER_FTPS			(CONST_METERS_PER_FOOT)
#define CONST_SQMETERS_PER_SQFOOT 	(CONST_METERS_PER_FOOT * CONST_METERS_PER_FOOT)
#define CONST_SQFEET_PER_SQMILE		(CONST_FEET_PER_MILE * CONST_FEET_PER_MILE)
#define CONST_SQMETERS_PER_SQMILE	(CONST_SQMETERS_PER_SQFOOT * CONST_SQFEET_PER_SQMILE)
#define CONST_SQMILES_PER_ACRE		(CONST_SQMETERS_PER_ACRE / CONST_SQMETERS_PER_SQMILE)
#define CONST_RADIANS_PER_DEGREE	(M_PI / 180.0)

/**
 * A class to use for simple muliplicative conversions between common units.  These
 * are set up as static constant double floating point factors that are compiled in, so
 * the speed of conversion is optimal.
 *
 * To use, simply take the unit you are converting from and multiply it times the appropriate
 * unit factor.
 *
 * For example, if you have miles per hour, and want meters per second, then you do:
 * mps = mph * MPS_PER_MPH;
 *
 *
 * Confirmed with source: http://www.sfei.org/it/gis/map-interpretation/conversion-constants
 */
class Units
{
public:
	// Time conversions
	STATIC_CONSTEXPR int SEC_PER_MIN = CONST_SEC_PER_MIN;
	STATIC_CONSTEXPR double MIN_PER_SEC = INVERT_EXPR(SEC_PER_MIN);

	STATIC_CONSTEXPR int MIN_PER_HR = CONST_MIN_PER_HR;
	STATIC_CONSTEXPR double HR_PER_MIN = INVERT_EXPR(MIN_PER_HR);

	STATIC_CONSTEXPR int SEC_PER_HR = CONST_SEC_PER_HR;
	STATIC_CONSTEXPR double HR_PER_SEC = INVERT_EXPR(SEC_PER_HR);

	STATIC_CONSTEXPR int HR_PER_DAY = CONST_HR_PER_DAY;
	STATIC_CONSTEXPR double DAY_PER_HR = INVERT_EXPR(HR_PER_DAY);

	STATIC_CONSTEXPR int SEC_PER_DAY = CONST_SEC_PER_DAY;
	STATIC_CONSTEXPR int DAY_PER_SEC = INVERT_EXPR(SEC_PER_DAY);

	// Distance unit conversions
	STATIC_CONSTEXPR double INCHES_PER_METER = CONST_INCHES_PER_METER;
	STATIC_CONSTEXPR double METERS_PER_INCH = INVERT_EXPR(INCHES_PER_METER);

	STATIC_CONSTEXPR double METERS_PER_FOOT = CONST_METERS_PER_FOOT;
	STATIC_CONSTEXPR double FEET_PER_METER = INVERT_EXPR(METERS_PER_FOOT);

	STATIC_CONSTEXPR int FEET_PER_MILE = CONST_FEET_PER_MILE;
	STATIC_CONSTEXPR double MILES_PER_FOOT = INVERT_EXPR(FEET_PER_MILE);

	STATIC_CONSTEXPR double METERS_PER_MILE = CONST_METERS_PER_MILE;
	STATIC_CONSTEXPR double MILES_PER_METER = INVERT_EXPR(METERS_PER_MILE);

	STATIC_CONSTEXPR double KM_PER_MILE = CONST_KM_PER_MILE;
	STATIC_CONSTEXPR double MILES_PER_KM = INVERT_EXPR(KM_PER_MILE);

	// Speed unit conversions
	STATIC_CONSTEXPR double KPH_PER_MPH = CONST_KPH_PER_MPH;
	STATIC_CONSTEXPR double MPH_PER_KPH = INVERT_EXPR(KPH_PER_MPH);

	STATIC_CONSTEXPR double MPS_PER_KPH = CONST_MPS_PER_KPH;
	STATIC_CONSTEXPR double KPH_PER_MPS = INVERT_EXPR(MPS_PER_KPH);

	STATIC_CONSTEXPR double MPS_PER_MPH = CONST_MPS_PER_MPH;
	STATIC_CONSTEXPR double MPH_PER_MPS = INVERT_EXPR(MPS_PER_MPH);

	STATIC_CONSTEXPR double MPS_PER_FTPS = CONST_MPS_PER_FTPS;
	STATIC_CONSTEXPR double FTPS_PER_MPS = INVERT_EXPR(MPS_PER_FTPS);

	// Area unit conversions
	STATIC_CONSTEXPR double SQMETERS_PER_SQFOOT = CONST_SQMETERS_PER_SQFOOT;
	STATIC_CONSTEXPR double SQFEET_PER_SQMETERS = INVERT_EXPR(SQMETERS_PER_SQFOOT);

	STATIC_CONSTEXPR double SQFEET_PER_SQMILE = CONST_SQFEET_PER_SQMILE;
	STATIC_CONSTEXPR double SQMILES_PER_SQFEET = INVERT_EXPR(SQFEET_PER_SQMILE);

	STATIC_CONSTEXPR double SQMETERS_PER_SQMILE = CONST_SQMETERS_PER_SQMILE;
	STATIC_CONSTEXPR double SQMILES_PER_SQMETER = INVERT_EXPR(SQMETERS_PER_SQMILE);

	STATIC_CONSTEXPR double SQMETERS_PER_ACRE = CONST_SQMETERS_PER_ACRE;
	STATIC_CONSTEXPR double ACRES_PER_SQMETERS = INVERT_EXPR(SQMETERS_PER_ACRE);

	STATIC_CONSTEXPR double SQMILES_PER_ACRE = CONST_SQMILES_PER_ACRE;
	STATIC_CONSTEXPR double ACRE_PER_SQMILE = INVERT_EXPR(SQMILES_PER_ACRE);

	// Angle unit conversions
	STATIC_CONSTEXPR double RADIANS_PER_DEGREE = CONST_RADIANS_PER_DEGREE;
	STATIC_CONSTEXPR double DEGREES_PER_RADIAN = INVERT_EXPR(RADIANS_PER_DEGREE);
};

} /* namespace messages */
} /* namespace tmx */

#undef EXPR
#undef INVERT_EXPR

#endif /* INCLUDE_UNITS_H_ */
