function riemannSum(a, b) {
    let width = 0.000001;
    let sum = 0;
    let position = a  // we start at a
    let val = 0;

    while (position < b) {
        val = exampleFunction(position);
        val *= width;
        sum += val;
        position += width;
    }
    return sum;
}


function exampleFunction(x) {
    return x ** 3 + 4;
}

var startTime = performance.now();
let v = riemannSum(0, 100);
var endTime = performance.now();

var seconds = (endTime - startTime) / 1000;
console.log(seconds)