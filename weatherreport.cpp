#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace
{    
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
    };
    /// <summary>
    /// This is a stub for a weather sensor. For the sake of testing 
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development
    /// </summary>
class HighPrecipLowWindStub : public IWeatherSensor {
    int Humidity() const override {
        return 80;
    }

    int Precipitation() const override {
        return 70; // High precipitation
    }

    double TemperatureInC() const override {
        return 30; // High temperature
    }

    int WindSpeedKMPH() const override {
        return 40; // Low wind speed
    }
};

void TestHighPrecipitation()
{
    HighPrecipLowWindStub sensor;

    string report = Report(sensor);
    cout << "Report: " << report << endl;

    // Strengthened assert to expose the bug
    assert(report.find("rain") != string::npos || report.find("Cloudy") != string::npos || report.find("Stormy") != string::npos);
}
