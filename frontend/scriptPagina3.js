function elegidoTamaño(Tamaño){
    postData("opcionesTamaño", Tamaño);
}

document.getElementById("tamaño1").addEventListener("click", function(){
    elegidoTamaño ("Vaso")
})

document.getElementById("tamaño2").addEventListener("click", function(){
    elegidoTamaño ("Jarra")
})
