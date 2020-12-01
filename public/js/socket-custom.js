var socket = io();

$('#crear').submit(function(event) {
    event.preventDefault();
    let ancho = document.getElementById('ancho').value;
    let alto = document.getElementById('alto').value;
    let color = document.getElementById('color').value;

    socket.emit('crearCuadrilatero', {
        ancho, alto, color
    });
});

socket.on('cuadrilateroActual', function(cuadrilatero) {
    let { ancho } = cuadrilatero;
    let { alto } = cuadrilatero;
    let { color } = cuadrilatero;
    let { area } = cuadrilatero;
    let { perimetro } = cuadrilatero;

    let dibujo = document.getElementById('dibujo');
    let anchoElement = document.getElementById('anchoLabel');
    let altoElement = document.getElementById('altoLabel');
    let colorElement = document.getElementById('colorLabel');
    let areaElement = document.getElementById('areaLabel');
    let perimetroElement = document.getElementById('perimetroLabel');
    
    dibujo.innerHTML = 
    `<rect width="${ancho}" height="${alto}" rx="1mm" rx="1mm" style="fill: ${color};"/>`;
    anchoElement.innerHTML = `Ancho: ${ancho}`;
    altoElement.innerHTML = `Alto: ${alto}`;
    colorElement.innerHTML = `Color: ${color}`;
    areaElement.innerHTML = `Area: ${area}`;
    perimetroElement.innerHTML = `Perimetro: ${perimetro}`;

});

socket.on('ultimoCuadrilatero', function(cuadrilatero) {
    let { ancho } = cuadrilatero;
    let { alto } = cuadrilatero;
    let { color } = cuadrilatero;
    let { area } = cuadrilatero;
    let { perimetro } = cuadrilatero;

    let dibujo = document.getElementById('dibujo');
    let anchoElement = document.getElementById('anchoLabel');
    let altoElement = document.getElementById('altoLabel');
    let colorElement = document.getElementById('colorLabel');
    let areaElement = document.getElementById('areaLabel');
    let perimetroElement = document.getElementById('perimetroLabel');
    
    dibujo.innerHTML = 
    `<rect width="${ancho}" height="${alto}" rx="1mm" rx="1mm" style="fill: ${color};"/>`;
    anchoElement.innerHTML = `Ancho: ${ancho}`;
    altoElement.innerHTML = `Alto: ${alto}`;
    colorElement.innerHTML = `Color: ${color}`;
    areaElement.innerHTML = `Area: ${area}`;
    perimetroElement.innerHTML = `Perimetro: ${perimetro}`;

});