document.addEventListener('keydown', function(event) {
    switch(event.keyCode){
        case 87: // w key
            document.getElementById("dot_up").style.background = "red";
            break;
        case 65: // a key
            document.getElementById("dot_left").style.background = "red";
            break;
        case 83: // s key
            document.getElementById("dot_down").style.background = "red";
            break;
        case 68: // d key
            document.getElementById("dot_right").style.background = "red";
            break;
        case 32: // space_bar key
        document.getElementById("space_bar").style.borderColor = "red";
            break;
    }       
});
document.addEventListener('keyup', function(event) {
    switch(event.keyCode){
        case 87: // w key
            document.getElementById("dot_up").style.background =
                 'rgb(' + 0 + ',' + 125 + ',' + 240 + ')';
            break;
        case 65: // a key
            document.getElementById("dot_left").style.background =
                 'rgb(' + 0 + ',' + 125 + ',' + 240 + ')';
            break;
        case 83: // s key
            document.getElementById("dot_down").style.background =
                 'rgb(' + 0 + ',' + 125 + ',' + 240 + ')';
            break;
        case 68: // d key
            document.getElementById("dot_right").style.background =
                 'rgb(' + 0 + ',' + 125 + ',' + 240 + ')';
            break;
        case 32: // space_bar key
        document.getElementById("space_bar").style.borderColor =
                 'rgb(' + 0 + ',' + 125 + ',' + 240 + ')';
            break;
        }       
    }
);