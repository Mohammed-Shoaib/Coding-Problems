// Problem Statement: https://www.hackerrank.com/challenges/js10-date/problem

function getDayName(dateString) {
    let weekdays = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    let day = new Date(dateString).getDay();
    return weekdays[day];
}