console.log("hello everyone!");
const text = document.getElementById("text");
const revolver = document.getElementById("revolver");
const shot = document.getElementById("shot");

(function() {
    var mousePos;
    
    document.onmousemove = handleMouseMove;
    setInterval(getMousePosition, 10); // setInterval repeats every X ms

    function handleMouseMove(event) {
        var dot, eventDoc, doc, body, pageX, pageY;

        event = event || window.event; // IE-ism

        // If pageX/Y aren't available and clientX/Y are,
        // calculate pageX/Y - logic taken from jQuery.
        // (This is to support old IE)
        if (event.pageX == null && event.clientX != null) {
            eventDoc = (event.target && event.target.ownerDocument) || document;
            doc = eventDoc.documentElement;
            body = eventDoc.body;

            event.pageX = event.clientX +
              (doc && doc.scrollLeft || body && body.scrollLeft || 0) -
              (doc && doc.clientLeft || body && body.clientLeft || 0);
            event.pageY = event.clientY +
              (doc && doc.scrollTop  || body && body.scrollTop  || 0) -
              (doc && doc.clientTop  || body && body.clientTop  || 0 );
        }

        mousePos = {
            x: event.pageX,
            y: event.pageY
        };
    }
    function getMousePosition() {
        var pos = mousePos;
        if (!pos) {
            // We haven't seen any movement yet
        }
        else {
            //console.log(pos.x, pos.y)
            text.innerHTML =pos.x+' '+ pos.y;
            // Use pos.x and pos.y
        
            centerImageAt(revolver,pos.x, pos.y);
            centerImageAt(shot,pos.x+20, pos.y-100);

        }
    }
    
})();
function centerImageAt(img,x, y) {
    
    // Ensure the image is fully loaded before calculating its dimensions
        const imgWidth = img.width;
        const imgHeight = img.height;

        // Calculate the top-left corner of the image to center it at (x, y)
        const left = x - imgWidth / 2;
        const top = y - imgHeight / 2;

        // Set the position of the image
        img.style.left = left + 'px';
        img.style.top = top + 'px';
    }

    addEventListener("click", (event) => {
        console.log("Clicked!")
        shot.style.visibility = "visible";
        setTimeout(function (){
            console.log("delayed")
            // Something you want delayed.
            shot.style.visibility = 'hidden';

          }, 100); 
    });
    document.onkeypress = function (e) {
        e = e || window.event;
        // use e.keyCode
        console.log(e.keyCode);
        if(e.keyCode == 114 || e.keyCode == 82){
            console.log("r");
            revolver.src = "view.png";
            
        }
    };
    
