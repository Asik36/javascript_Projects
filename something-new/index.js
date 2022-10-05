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
document.addEventListener('keydown', function(event) {
      if (event.repeat) return;
    switch(event.keyCode){
        case 87: // w key
            document.getElementById("dot_up").style.background = "red";
            if(bool_up){
                hit.cloneNode(true).play();
            } else{
                miss.cloneNode(true).play();
            }
        break;
        
        case 65: // a key
            document.getElementById("dot_left").style.background = "red";
            if(bool_right){
                hit.cloneNode(true).play();
            } else{
                miss.cloneNode(true).play();
            }
            break;
        break;
        case 83: // s key
            document.getElementById("dot_down").style.background = "red";
            if(bool_down){
                hit.cloneNode(true).play();
            } else{
                miss.cloneNode(true).play();
            }
            break;
        break;
        case 68: // d key
        document.getElementById("dot_right").style.background = "red";
        if(bool_left){
            hit.cloneNode(true).play();
        } else{
            miss.cloneNode(true).play();
        }
        break;
        
        break;
        case 32: // space_bar key
        document.getElementById("space_bar").style.borderColor = "red";
        if(bool_space){
            snd.play().cloneNode(true).play();
        } else{
            miss.cloneNode(true).play();
        }
        break;
    }
});



function myFunction(){
    bool = false;
}
function startNote(){
    bool_up = true;
    setTimeout(function(){bool_up}, 3000);

}
var bool_left, bool_right, bool_up, bool_down,bool_space = false;
var color_left, color_right, color_up, color_down, color_space = "blue";
var hit = new Audio("hit.wav"); // buffers automatically when created
var miss = new Audio("hit2.wav"); // buffers automatically when created


function song(){
    
}

function remove() {
    song();
    var elem = document.getElementById('btn_start');
    elem.parentNode.removeChild(elem);
    return false;
}

function noteUp(){
    var note = document.createElement("div");
    note.classList.add("Note");
    document.getElementById('dot_up').append(note);
    
}
noteUp();