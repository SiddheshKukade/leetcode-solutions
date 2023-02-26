SELECT weather.id 
FROM 
    weather
        JOIN
    weather w on DATEDIFF(weather.recordDate , w.recordDate) = 1 #checking prev days
        AND weather.Temperature > w.Temperature # checking if the curr temperature is highest or not.
;
