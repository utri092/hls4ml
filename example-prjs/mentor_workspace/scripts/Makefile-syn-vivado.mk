help:
	@echo "INFO: make <TAB> for usage"
.PHONY: help

gui:
	vivado_hls -p keras1layer_prj
.PHONY: gui

hls-sh:
	vivado_hls -f ./build_prj.tcl
.PHONY: hls-sh

report:
	@../../scripts/report-vivado.sh $(PROJECT) | tee report.log
.PHONY: report

validate-c:
	@python ../../scripts/validate.py -r ./tb_data/tb_output_predictions.dat -i ./tb_data/csim_results.log | tee validate-c.log
.PHONY: validate-c

validate-rtl:
	@python ../../scripts/validate.py -r ./tb_data/tb_output_predictions.dat -i ./tb_data/rtl_cosim_results.log | tee validate-rtl.log
.PHONY: validate-rtl

clean:
	@echo "INFO: make ultraclean"
.PHONY: clean

ultraclean: clean
	rm -rf *.log *.csv ./*_prj tb_data/*_csim_results.log tb_data/*_rtl_cosim_results.log
.PHONY: ultraclean
