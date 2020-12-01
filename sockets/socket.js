const { io } = require('../server/server');
const cuadrilatero = require('../build/Release/cuadrilatero');

io.on('connection', (client) => {
    client.emit('cuadrilateroActual', {
        perimetro: cuadrilatero.calcularPerimetro(),
        area: cuadrilatero.calcularArea(),
        ancho: cuadrilatero.obtenerAncho(),
        alto: cuadrilatero.obtenerAlto(),
        color: cuadrilatero.obtenerColor()
    });

    client.on('crearCuadrilatero', (data) => {
        let { ancho } = data;
        let { alto } = data;
        let { color } = data;

        cuadrilatero.crear(Number(ancho), Number(alto), color);
        let perimetro = cuadrilatero.calcularPerimetro();
        let area = cuadrilatero.calcularArea();
        ancho = cuadrilatero.obtenerAncho();
        alto = cuadrilatero.obtenerAlto();
        color = cuadrilatero.obtenerColor();

        client.broadcast.emit('ultimoCuadrilatero', {
            ancho,
            alto,
            color,
            perimetro,
            area
        });

        client.emit('cuadrilateroActual', {
            perimetro: cuadrilatero.calcularPerimetro(),
            area: cuadrilatero.calcularArea(),
            ancho: cuadrilatero.obtenerAncho(),
            alto: cuadrilatero.obtenerAlto(),
            color: cuadrilatero.obtenerColor()
        });

    });
});