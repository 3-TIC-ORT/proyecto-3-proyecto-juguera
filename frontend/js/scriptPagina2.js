function elegidoSabor(Sabor){
    postData("opcionesSabor", Sabor);
    window.location.href = 'pagina3.html';
}

document.getElementById("sabor1").addEventListener("click", function(){
    elegidoSabor ("Manzana")
})

document.getElementById("sabor2").addEventListener("click", function(){
    elegidoSabor ("Naranja")
})

document.getElementById("sabor3").addEventListener("click", function(){
    elegidoSabor ("Limon")
})

document.getElementById("sabor4").addEventListener("click", function(){
    elegidoSabor ("Frutilla")
})

