$(function(){
    // $('.main-menu').find('li').on('click', function(event){
    //     $(this).siblings().removeClass('active');
    //     $(this).addClass('active');
    // });

    $.get("/prepare/load", function(dataArray){
        var currencyData = [], labelsData = [], forecastData = [];
        JSON.parse(dataArray).map(function(item){
            console.log(item);
            forecastData.push(item['forecast']);
            currencyData.push(item['value']);
            // делаем красивую дату
            var d = item['date'].split('-');
            labelsData.push(d[2]+'.'+d[1]);
        });
        // currencyData.pop();
        var testChart = new Chart($('#test-chart'), {
            type: 'line',
            data: {
                labels: labelsData,
                // xLabels: labelsData,
                datasets: [{
                    label: 'Last ' + currencyData.length + ' days USD currency (BYN)',
                    data: currencyData,
                    backgroundColor: 'rgba(223,58,1,0.2)',
                    borderColor: 'rgba(223,58,1,1)',
                    pointBackgroundColor: 'rgba(223,58,1,1)',
                    pointRadius: 4,
                    pointHoverRadius: 8,
                    fill: true,
                },{
                    label: 'Neural network forecast for ' + currencyData.length + ' days (BYN)',
                    data: forecastData,
                    backgroundColor: 'rgba(8,138,8,0.2)',
                    borderColor: 'rgba(8,138,8,1)',
                    pointBackgroundColor: 'rgba(8,138,8,1)',
                    pointRadius: 4,
                    pointHoverRadius: 8,
                    fill: true,
                }]
            },
            options: {}
        });
    });
});
