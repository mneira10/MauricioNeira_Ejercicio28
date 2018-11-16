#!/bin/bash
#PBS -l nodes=1:ppn=4,mem=1gb,walltime=00:10:00
#PBS -M m.neira10@uniandes.edu.co
#PBS -m abe
#PBS -N mneira10_sample
#PBS -j oe


module load anaconda/python3 
module load gcc/4.9.4 
module load openmpi/1.8.5
cd /hpcfs/home/fisi4028/m.neira10/MauricioNeira_Ejercicio27/2nda_parte
make
