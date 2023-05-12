# Análisis y diseño de algoritmos avanzados

Transmisiones de datos comprometidas

Cuando se transmite información de un dispositivo a otro, se transmite una serie sucesiva de bits, que llevan una cabecera, datos y cola. Existe mucha gente mal intencionada, que puede interceptar estas transmisiones, modificar estas partes del envío, y enviarlas al destinatario, incrustando sus propios scripts o pequeños programas que pueden tomar cierto control del dispositivo que recibe la información

Suponiendo que conocemos secuencias de bits de código mal intencionado:

¿serías capaz de identificarlo dentro del flujo de bits de una transmisión?
¿podremos identificar si el inicio de los datos se encuentra más adelante en el flujo de bits?
Si tuviéramos dos transmisiones de información y sospechamos que en ambas han sido intervenidas y que traen el mismo código malicioso, ¿podríamos dar propuestas del código mal intencionado ?