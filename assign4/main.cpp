/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob
 * Roberts-Baca.
 */

#include <algorithm>
#include <iostream>
#include <random>
#include <ranges>
#include <vector>

/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
    double min_temp;
    double max_temp;
    double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
    // STUDENT TODO 1: return a forecast for the daily weather that is passed
    // in.
    return {
        *std::min_element(dailyWeather.begin(), dailyWeather.end()),
        *std::max_element(dailyWeather.begin(), dailyWeather.end()),
        std::accumulate(dailyWeather.begin(), dailyWeather.end(), 0.0) /
            dailyWeather.size(),
    };
}

std::vector<Forecast>
get_forecasts(const std::vector<std::vector<double>>& weatherData) {
    /*
     * STUDENT TODO 2: returns a vector of Forecast structs for the weatherData
     * which contains std::vector<double> which contain values for the weather
     * on that day.
     */
    std::vector<Forecast> results;
    std::transform(weatherData.begin(), weatherData.end(),
                   std::back_inserter(results), compute_forecast);
    return results;
}

std::vector<Forecast>
get_filtered_data(const std::vector<Forecast>& forecastData) {
    // STUDENT TODO 3: return a vector with Forecasts filtered for days with
    // specific weather.
    std::vector<Forecast> results{forecastData};

    auto pred = [](Forecast f) {
        return f.max_temp - f.min_temp > kMaxTempRequirement &&
               f.avg_temp >= uAvgTempRequirement;
    };
    results.erase(std::remove_if(results.begin(), results.end(), pred));
    return results;
};

std::vector<Forecast>
get_shuffled_data(const std::vector<Forecast>& forecastData) {
    // STUDENT TODO 4: Make use of a standard library algorithm to shuffle the
    // data!
    std::random_device rd;
    std::mt19937 g(rd());

    std::vector<Forecast> results{forecastData};

    std::shuffle(results.begin(), results.end(), g);
    return results;
}

std::vector<Forecast>
run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
    // STUDENT TODO 5: Put your functions together to run the weather pipeline!
    return get_shuffled_data(get_filtered_data(get_forecasts(weatherData)));
}

/* #### Please don't change this line! #### */
#include "utils.cpp"
