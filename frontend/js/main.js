var i18n = {
    data: [
        ['en', 'ru', 'by'],
        ['Neural Network', 'Нейронная сеть', 'Нейронавая сетка'],
        ['Forecast', 'Прогноз', 'Прагноз'],
        ['Description', 'Описание', 'Апісанне'],
        ['Settings', 'Настройки', 'Налады'],
        ['English', 'Английский язык', 'Англійская мова'],
        ['Russian', 'Русский язык', 'Руская мова'],
        ['Belarussian', 'Белорусский язык', 'Беларуская мова'],
        ['About', 'О программе', 'Аб праграме'],
        ['See on Github', 'Смотреть на Github', 'Глядзець на Github'],
        ['Wrong results', 'Ошибочные результаты', 'Памылковыя вынікі'],
        ['Loading', 'Загрузка', 'Загрузка'],
        ['Neural network forecast for', 'Прогноз нейронной сети для', 'Прагноз нейронавай сеткі для'],
        ['days', 'дней', 'дзён'],
        ['USD currency for', 'Курс доллара для', 'Курс долара для'],
        ['last days', 'последних дней', 'апошніх дзён'],
        ['Dmitry Marchenko', 'Дмитрий Марченко', 'Дзмітрый Марчанка'],
        ['of', 'из', 'з'],
        ['Average error', 'Средняя ошибка', 'Сярэдняя памылка'],
        ['Tomorrow', 'Завтра', 'Заўтра'],
        ['This site is a visualization of the work of a neural network.', 'Данный сайт является визуализацией работы нейронной сети.', 'Гэты сайт з\'яўляецца візуалізацыяй працы нейронавай сеткі.'],
        ['Developed for the thesis project Dmitry S. Marchenko, 4th year student of the BV group, specialty "Informatics", the Faculty of Mathematics and Natural Sciences, Mogilev State University named after Kuleshov',
        'Разработано для дипломного проекта Марченко Дмитрия Сергеевича, студента 4 курса группы "БВ", специальности "Информатика", факультета математики и естествознания, Могилёвского государственного университета им. А.А. Кулешова',
        'Распрацавана для дыпломнага праекта Марчанка Дзмітрыя Сяргеевіча, студэнта 4 курса групы "БВ", спецыяльнасці "Інфарматыка", факультэта матэматыкі і прыродазнаўства, Магілёўскага дзяржаўнага ўніверсітэта ім. А.А. Куляшова'],
        ['The main characteristics of the neural network', 'Основные характеристики нейронной сети', 'Асноўныя характарыстыкі нейронавай сеткі'],
        ['Characteristic', 'Характеристика', 'Характарыстыка'],
        ['Value', 'Значение', 'Значэнне'],
        ['Neural Network Architecture', 'Архитектура нейронной сети', 'Архітэктура нейронавай сеткі'],
        ['Multilayer Perceptron', 'Многослойный перцептрон', 'Шматслаёвы перцэптрон'],
        ['Learning Algorithm', 'Алгоритм обучения', 'Алгарытм навучання'],
        ['Method of back propagation error', 'Метод обратного распространения ошибки', 'Метад зваротнага распаўсюджвання памылкі'],
        ['Activation function', 'Функция активации', 'Функцыя актывацыі'],
        ['The sigmoidal function with an interval of values (-1; 1)', 'Сигмоидальная функция с интервалом значений (-1; 1)', 'Сыгмаідальная функцыя з інтэрвалам значэнняў (-1; 1)'],
        ['Input data', 'Входные данные', 'Ўваходныя дадзеныя'],
        ['Time series of dollar exchange rate increments', 'Временной ряд приращений курса доллара', 'Часовы шэраг прырашчэння курсу даляра'],
        ['Output data', 'Выходные данные', 'Выхадныя дадзеныя'],
        ['The increment relative to the last dollar value', 'Приращение относительно последнего значения курса доллара', 'Прырашчэнне адносна апошняга значэння курсу даляра'],
        ['Data source', 'Источник данных', 'Крыніца дадзеных'],
        ['The values of the stock exchange, received via the API <a href="http://nbrb.by/" class="external-link" _target="blank">NBRB site</a>',
        'Значения фондовой биржи, полученные с помощью API <a href="http://nbrb.by/" class="external-link" _target="blank">сайта НБРБ</a>',
        'Значэння фондавай біржы, атрыманыя з дапамогай API <a href="http://nbrb.by/" class="external-link" _target="blank">сайта НБРБ</a>']
    ],
    get: function(code, default_lang = 'en', search_by = 'en') {
        var result = null, 
            code_lang = this.data[0].lastIndexOf(default_lang), 
            search_lang = this.data[0].lastIndexOf(search_by);
        if (typeof code == 'number') result = this.data[code][code_lang];
        else {
            this.data.map(function(item){
                if (item[search_lang]==code) result = item[code_lang];
            });
            if (result==null) result = code;
        }
        return result;
    }
};

var getUrlParameter = function getUrlParameter(sParam) {
    var sPageURL = decodeURIComponent(window.location.search.substring(1)),
        sURLVariables = sPageURL.split('&'),
        sParameterName,
        i;

    for (i = 0; i < sURLVariables.length; i++) {
        sParameterName = sURLVariables[i].split('=');
        if (sParameterName[0] === sParam) {
            return sParameterName[1] === undefined ? true : sParameterName[1];
        }
    }
};

$(function(){
    var lang_param = getUrlParameter('lang'), 
        current_lang = typeof lang_param == 'undefined' ? 'ru' : lang_param,
        days_count = getUrlParameter('days') ? getUrlParameter('days') : 15;
    $('.i18n').each(function(e){
        var before_translate = $(this).html(),
            after_translate = i18n.get(before_translate, current_lang);
        $(this).html(after_translate);
    });
    
    $.get("/prepare/load?days="+days_count, function(dataArray){
        var currencyData = [], labelsData = [], forecastData = [];
        var notFirst = false, prev, wrong = 0, delta = 0, delta_perc = 0;
        dataArray = JSON.parse(dataArray);
        var tommorow = dataArray.pop();
        dataArray.map(function(item){
            if (notFirst) {
                var diff_value = item['value'] - prev['value'],
                    diff_forecast = item['forecast'] - prev['forecast'];
                if (diff_forecast*diff_value<=0) wrong++;
            }
            delta += Math.abs(item['value']-item['forecast']);
            delta_perc += Math.abs(item['value']-item['forecast']) / item['value'];
            forecastData.push(item['forecast']);
            currencyData.push(item['value']);
            // делаем красивую дату
            var d = item['date'].split('-');
            labelsData.push(d[2]+'.'+d[1]);
            notFirst = true;
            prev = item;
        });
        $(".wrong-answers").html(wrong+' '+i18n.get('of',current_lang)+' '+(currencyData.length - 1));
        $(".wrong-answers-p").html((wrong/(currencyData.length - 1)*100).toFixed(2)+'%');
        $(".avg-error").html('&plusmn; ' + (delta / currencyData.length).toFixed(4) + ' BYN');
        $(".avg-error-p").html((delta_perc / currencyData.length * 100).toFixed(2)+'%');
        $(".tomorrow-forecast").html(tommorow.forecast + ' BYN');
        var tommorow_class = 'green',
            tommorow_forecast = parseFloat(tommorow.forecast), 
            last_value = parseFloat(dataArray[dataArray.length-1].value);
        if (tommorow_forecast < last_value) tommorow_class = 'red';
        else if (tommorow_forecast == last_value) tommorow_class = 'yellow';
        $(".tomorrow-forecast-p").html('<div class="' + tommorow_class + '-arrow">&rarr;</div>');
        var testChart = new Chart($('#test-chart'), {
            type: 'line',
            data: {
                labels: labelsData,
                datasets: [{
                    label: i18n.get('USD currency for', current_lang) + ' ' + currencyData.length + ' '+i18n.get('last days', current_lang)+' (BYN)',
                    data: currencyData,
                    backgroundColor: 'rgba(223,58,1,0.2)',
                    borderColor: 'rgba(223,58,1,1)',
                    pointBackgroundColor: 'rgba(223,58,1,1)',
                    pointRadius: 4,
                    pointHoverRadius: 8,
                    fill: true,
                    lineTension: 0
                },{
                    label: i18n.get('Neural network forecast for', current_lang)+' ' + currencyData.length + ' '+i18n.get('days', current_lang)+' (BYN)',
                    data: forecastData,
                    backgroundColor: 'rgba(8,138,8,0.2)',
                    borderColor: 'rgba(8,138,8,1)',
                    pointBackgroundColor: 'rgba(8,138,8,1)',
                    pointRadius: 4,
                    pointHoverRadius: 8,
                    fill: true,
                    lineTension: 0
                }]
            },
            options: {}
        });
    });
});
