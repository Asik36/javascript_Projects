function whatever(color) {
    console.log(color);
    document.getElementById("background_color").style.background = color;
    
}

function getRandomColor() {
    var letters = '0123456789ABCDEF';
    var color = '#';
    for (var i = 0; i < 6; i++) {
        color += letters[Math.floor(Math.random() * letters.length)];
    }
    return color;
}
function getInput(){
    let r = document.getElementById("myR").value;
    let g = document.getElementById("myG").value;
    let b = document.getElementById("myB").value;
    console.log(rgbToHex(r, g, b));
    document.getElementById("background_color").style.background = rgbToHex(r, g, b);
}
function rgbToHex(red, green, blue) {
    const rgb = (red << 16) | (green << 8) | (blue << 0);
    return '#' + (0x1000000 + rgb).toString(16).slice(1);
}

function func(){
    if(document.getElementById("switchCheck").checked){
        console.log("checked");
        whatever(getRandomColor());
    }
}
setInterval(func, 100);

