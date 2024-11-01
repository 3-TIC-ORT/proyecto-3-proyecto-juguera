const empezarLimpieza = document.getElementById("empezarLimpieza");
empezarLimpieza.addEventListener("click", async()=>{
    let limpieza = "limpieza"
    postData("EmpezarLimpieza", limpieza);
})