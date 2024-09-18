function elegidoSabor(Sabor){
    postData("opcionesSabor", Sabor);
}

document.getElementById("sabor1").addEventListener("click", function(){
    elegidoSabor ("sabor1")
})

document.getElementById("sabor2").addEventListener("click", function(){
    elegidoSabor ("sabor2")
})

document.getElementById("sabor3").addEventListener("click", function(){
    elegidoSabor ("sabor3")
})

document.getElementById("sabor4").addEventListener("click", function(){
    elegidoSabor ("sabor4")
})

