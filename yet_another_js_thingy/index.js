/**
 * set the color
 * @param {string} color  the new color
 */
function whatever(color) {
    const { r, g, b } = hexToRGB(color);
    document.getElementById("myR").value = r;
    document.getElementById("myG").value = g;
    document.getElementById("myB").value = b;

    document.getElementById("background_color").style.background = color;
    


}
/**
 * get random hex value
 * @param {string} color  the new color
 */
function getRandomColor() {
    const letters = '0123456789ABCDEF';
    let color = '#';
    for (let i = 0; i < 6; i++) {
        color += letters[Math.floor(Math.random() * letters.length)];
    }
    return color;
}
function getInput(){
    let r = document.getElementById("myR").value;
    let g = document.getElementById("myG").value;
    let b = document.getElementById("myB").value;
    document.getElementById("background_color").style.background = rgbToHex(r, g, b);
}
function rgbToHex(red, green, blue) {
    const rgb = (red << 16) | (green << 8) | (blue << 0);
    return '#' + (0x1000000 + rgb).toString(16).slice(1);
}

function hexToRGB(hex) {
    hex = hex.replace(/[^0-9A-F]/gi, '');// what does it meannbn
    var bigint = parseInt(hex, 16);
    var r = (bigint >> 16) & 255;
    var g = (bigint >> 8) & 255;
    var b = bigint & 255;

    return { r, g, b };
}





function func(){
    if(document.getElementById("switchCheck").checked)
        party_mode = setInterval(function() { whatever(getRandomColor()); }, 100);
    else
        clearInterval(party_mode);
}
