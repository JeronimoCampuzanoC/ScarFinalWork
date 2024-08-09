#!/bin/bash
#SBATCH --partition=learning
#SBATCH --nodes=1
#SBATCH --time=05:00:00
#SBATCH --job-name=MMM-SCAR
#SBATCH -o %x_%j.out
#SBATCH -e %x_%j.err
#SBATCH --exclusive

ulimit -s unlimited
cd /home/JERONIMO_CAMPUZANO/SCARFINALWORK/bin
./mmm